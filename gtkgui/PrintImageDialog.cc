/*
 *   surf - visualizing algebraic curves and algebraic surfaces
 *   Copyright (C) 1996-1997 Friedrich-Alexander-Universitaet
 *                           Erlangen-Nuernberg
 *                 1997-2000 Johannes Gutenberg-Universitaet Mainz
 *   Authors: Stephan Endrass, Hans Huelf, Ruediger Oertel,
 *            Kai Schneider, Ralf Schmitt, Johannes Beigel
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

/**************************************************************************
    Projectteam 'Qualifizierung und Weiterentwicklung eines Software-Pakets
		 zur Darstellung reell-algebraischer Kurven und Flächen'
    from Fachhochschule Frankfurt am Main (University of Applied Sciences)

    Authors: Stephan Haasmann, Sven Sperner
    Changes: new File, support for CUPS-Printing
    Date: Wintersemester 2009/2010
    Last changed: 2010/01/14

**************************************************************************/

#include <strstream>

#include "PrintImageDialog.h"
using namespace std;

using std::ostrstream;

char* printerName = (char*)"none";

/*
 * change Dither-Method
 */
void PrintImageDialog::toggled_dither_method (GtkWidget *w, gpointer data)
{
	PrintImageDialog *sid = (PrintImageDialog *)data;
	sid->ditherChanged (w);
}

/*
 * Dither-Method changed
 */
void PrintImageDialog::ditherChanged(GtkWidget *w)
{
        if( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(w))) {
                gtk_widget_set_sensitive(ditherSteps,FALSE);
	} else{
		gtk_widget_set_sensitive(ditherSteps,TRUE);
	}
}

/*
 * hide Dither-Method
 */
void PrintImageDialog::hide_dither_method( GtkWidget *w, gpointer data )
{
          gtk_widget_set_sensitive((GtkWidget *)data,FALSE);
}

/*
 * show Dither-Method
 */
void PrintImageDialog::show_dither_method( GtkWidget *w, gpointer data )
{
          gtk_widget_set_sensitive((GtkWidget *)data,TRUE);
}

/*
 * generate Script and temporary Picture
 */
char *PrintImageDialog::generateScript()
{
	SymbolTable st;
	wrw.writeSymbols (st);
	ostrstream ostr;
	ostr << st;
	ostr << "filename = \"" << "/tmp/surf" << "\";" << endl
	     << (type==color ? "save_color_image;" : "save_dithered_image;") << endl
	     << ends;
	return ostr.str();
}

/*
 * initialise Printdialog
 */
PrintImageDialog::PrintImageDialog()
{
	printerSelectionDialog = gtk_dialog_new();
	gtk_signal_connect (GTK_OBJECT(printerSelectionDialog), "delete_event", GTK_SIGNAL_FUNC(handle_delete), this);
	gtk_window_set_default_size (GTK_WINDOW(printerSelectionDialog), 400, 250);

	GtkWidget *box = gtk_hbox_new (TRUE, 10);
	GtkWidget *xbox = gtk_vbox_new (FALSE, 10);
	colorBox   = gtk_vbox_new (FALSE, 2);
	bwBox      = gtk_vbox_new (FALSE, 2);
        ditherBox  = gtk_hbox_new( TRUE,0 );
        ditherBBox = gtk_hbox_new( TRUE,0 );
	buttonBox  = gtk_hbutton_box_new( );
	printerBox = gtk_hbox_new( FALSE,0 );
	scaleBox   = gtk_vbox_new( FALSE,0 );
	pagesBox   = gtk_vbox_new( FALSE,0 );
	formatBox  = gtk_vbox_new( FALSE,0 );
	adjustBox  = gtk_hbox_new( FALSE,0 );

	/* create and handle Printer-Table */
	numPrinters = cupsGetDests(&printers);
	gchar* printers[4];
	printerList= gtk_clist_new( 4 );
	gtk_box_pack_start( GTK_BOX(printerBox), printerList, TRUE, TRUE, 0 );
	gtk_clist_set_selection_mode( GTK_CLIST(printerList), GTK_SELECTION_SINGLE );
	gtk_clist_set_column_title( GTK_CLIST(printerList), 0, "Printer" );
	gtk_clist_set_column_title( GTK_CLIST(printerList), 1, "Default" );
	gtk_clist_set_column_title( GTK_CLIST(printerList), 2, "Media" );
	gtk_clist_set_column_title( GTK_CLIST(printerList), 3, "" );
	gtk_clist_set_column_width( GTK_CLIST(printerList), 0, 150 );
	gtk_clist_set_column_width( GTK_CLIST(printerList), 1, 60 );
	gtk_clist_set_column_width( GTK_CLIST(printerList), 2, 40 );
	gtk_clist_set_column_width( GTK_CLIST(printerList), 3, 200 );
	gtk_clist_column_titles_show( GTK_CLIST(printerList) );
	for(int i=0 ; i<10 ; i++)
	{
		if(i<numPrinters)
		{
			printers[0]=getPrinterName(i);
			if(isPrinterDefault(i) > 0)
				printers[1]=(gchar*)"yes";
			else
				printers[1]=(gchar*)"no";
			printers[2]=(gchar*)getOptionByName(printers[0],(char*)"media");
			printers[3]=(gchar*)"";
		}
		else
		{
			printers[0]=(gchar*)"";
			printers[1]=(gchar*)"";
			printers[2]=(gchar*)"";
			printers[3]=(gchar*)"";
		}
		gtk_clist_append( GTK_CLIST(printerList), printers );
	}
        gtk_signal_connect(GTK_OBJECT(printerList), "select_row", (GtkSignalFunc)printer_selected,GTK_OBJECT(printerList));

	/* create and handle Scaling Option */
	scaleLbl = gtk_label_new( "Scaling" );
	scaleAdj = gtk_adjustment_new( 100, 1, 800, 1, 10, 0 );
	scaleSpin = gtk_spin_button_new( GTK_ADJUSTMENT(scaleAdj), 0.0, 0 );
	scaleRadio1 = gtk_radio_button_new_with_label (NULL, "\% of Page");
	scaleGroup = gtk_radio_button_group (GTK_RADIO_BUTTON (scaleRadio1));
	scaleRadio2 = gtk_radio_button_new_with_label(scaleGroup, "\% of Image");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (scaleRadio1), TRUE);
	gtk_box_pack_start (GTK_BOX(scaleBox), scaleLbl, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX(scaleBox), scaleSpin, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX(scaleBox), scaleRadio1, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX(scaleBox), scaleRadio2, FALSE, FALSE, 0);

	/* create and handle Number of Pages Option */
	pagesLbl = gtk_label_new( "Copies" );
	pagesAdj = gtk_adjustment_new( 1, 1, 100, 1, 10, 0 );
	pagesSpin = gtk_spin_button_new( GTK_ADJUSTMENT(pagesAdj), 0.0, 0 );
	gtk_box_pack_start (GTK_BOX(pagesBox), pagesLbl, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX(pagesBox), pagesSpin, FALSE, FALSE, 0);

	/* create and handle Orientation Option */
	formatLbl = gtk_label_new( "Orientation" );
	formatRadio1 = gtk_radio_button_new_with_label (NULL, "Portrait");
	formatGroup = gtk_radio_button_group (GTK_RADIO_BUTTON (formatRadio1));
	formatRadio2 = gtk_radio_button_new_with_label(formatGroup, "Landscape");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (formatRadio1), TRUE);
	gtk_box_pack_start (GTK_BOX(formatBox), formatLbl, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX(formatBox), formatRadio1, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX(formatBox), formatRadio2, FALSE, FALSE, 0);

	/* create and handle Buttons */
	okButton     = gtk_button_new_with_label ("OK");
	cancelButton = gtk_button_new_with_label ("Cancel");
	gtk_box_pack_start (GTK_BOX(buttonBox), okButton, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(buttonBox), cancelButton, TRUE, TRUE, 0);

	gtk_box_pack_start (GTK_BOX(adjustBox), scaleBox, TRUE, TRUE, 10);
	gtk_box_pack_start (GTK_BOX(adjustBox), pagesBox, TRUE, TRUE, 10);
	gtk_box_pack_start (GTK_BOX(adjustBox), formatBox, TRUE, TRUE, 10);

	gtk_box_pack_start (GTK_BOX(box), colorBox, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(box), bwBox,    TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(xbox), box,    TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(ditherBBox), ditherBox, TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(xbox), ditherBBox,    TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(xbox), printerBox,    TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(xbox), adjustBox,    TRUE, TRUE, 0);
	gtk_box_pack_start (GTK_BOX(xbox), buttonBox,    TRUE, TRUE, 0);

	/* create and handle Image Options */
	OptionMenuBuilder omb;
	omb.addOption ("JPEG file (.jpg)", "jpg");
	omb.addOption ("portable pixmap (.ppm)", "ppm");
			
	GtkWidget *om=omb.getOptionMenu();
	gtk_box_pack_start (GTK_BOX(colorBox), om, TRUE, TRUE, 0);
	wrw.addWidget (om, "color_file_format");
	
	GtkWidget * trueColor = omb.addOption ("true color"        , "TrueColor");
	GtkWidget * netscape  = omb.addOption ("netscape colormap" , "Netscape" );
	GtkWidget * optimized = omb.addOption ("optimized colormap", "Optimized");

        gtk_signal_connect (GTK_OBJECT (trueColor),"activate",(GtkSignalFunc)hide_dither_method,GTK_OBJECT(ditherBox));
        gtk_signal_connect (GTK_OBJECT (netscape), "activate",(GtkSignalFunc)hide_dither_method,GTK_OBJECT(ditherBox));
        gtk_signal_connect (GTK_OBJECT (optimized),"activate",(GtkSignalFunc)show_dither_method,GTK_OBJECT(ditherBox));

	om=omb.getOptionMenu();
	gtk_box_pack_start (GTK_BOX(colorBox), om, TRUE, TRUE, 0);
	wrw.addWidget (om, "color_file_colormap");

	omb.addOption ("portable bitmap (.pbm)"        , "pbm");
	omb.addOption ("X11 bitmap (.xbm)"             , "X11_bitmap");
	om=omb.getOptionMenu();
	gtk_box_pack_start (GTK_BOX(bwBox), om, TRUE, TRUE, 0);
	wrw.addWidget (om, "dither_file_format");

	omb.addOption ("150 dpi" , "res_150dpi" );
	omb.addOption ("300 dpi" , "res_300dpi" );
	omb.addOption ("600 dpi" , "res_600dpi" );
	omb.addOption ("1200 dpi", "res_1200dpi");

	gtk_box_pack_start (GTK_BOX(bwBox), om=omb.getOptionMenu(), TRUE, TRUE, 0);
	
	gtk_option_menu_set_history (GTK_OPTION_MENU(om), 3);
 	gtk_menu_set_active (GTK_MENU(gtk_option_menu_get_menu(GTK_OPTION_MENU(om))), 3);

	wrw.addWidget (om, "resolution");

	ditherColors = gtk_check_button_new_with_label ("dither colors:");
	gtk_box_pack_start (GTK_BOX(ditherBox), ditherColors, FALSE, FALSE,0);
	ditherSteps = mygtk_new_spin (20.0, 0.01, 255.0, 0.01, 1.0, 0.1, 1);
	gtk_widget_set_sensitive (ditherSteps, FALSE);
	gtk_box_pack_start (GTK_BOX(ditherBox), ditherSteps, TRUE, TRUE, 0);
        gtk_signal_connect( GTK_OBJECT(ditherColors),"pressed",(GtkSignalFunc)toggled_dither_method,this );

	wrw.addWidget (ditherColors, "dither_colors");
	wrw.addWidget (ditherSteps, "dither_steps");

	gtk_box_pack_start    (GTK_BOX(GTK_DIALOG(printerSelectionDialog)->vbox), xbox, FALSE, FALSE, 0);
	gtk_box_reorder_child (GTK_BOX(GTK_DIALOG(printerSelectionDialog)->vbox), xbox, 0);
}

/*
 * show Printdialog
 */
void PrintImageDialog::show(PrintImageDialog::imageType t)
{
	type = t;
	if (t == color) {
		gtk_window_set_title (GTK_WINDOW(printerSelectionDialog), "Print color image as...");
		gtk_widget_set_sensitive (colorBox, TRUE);
		gtk_widget_set_sensitive (bwBox, FALSE);
		gtk_widget_set_sensitive (ditherBBox, TRUE);
	} else {
		gtk_window_set_title (GTK_WINDOW(printerSelectionDialog), "Print dithered image as...");
		gtk_widget_set_sensitive (colorBox, FALSE);
		gtk_widget_set_sensitive (bwBox, TRUE);
		gtk_widget_set_sensitive (ditherBBox, FALSE);
	}
	gtk_widget_show_all(printerSelectionDialog);
	gdk_window_raise(printerSelectionDialog->window);
}

/*
 * delete Printdialog
 */
gint PrintImageDialog::handle_delete (GtkWidget *widget, GdkEvent *event, gpointer data)
{
	gtk_widget_hide (widget);
	return TRUE;
}


/*
 * get Name of a Printer
 */
char* PrintImageDialog::getPrinterName(int destnum)
{
	if(numPrinters >= destnum)
	{
		printer = printers;
		printer += destnum;
		return (char*)printer->name;
	}
	else
		return (char*)"none";
}

/*
 * is Printer marked as default?
 */
int PrintImageDialog::isPrinterDefault(int destnum)
{
	if(numPrinters >= destnum)
	{
		printer = printers;
		printer += destnum;
		return printer->is_default;
	}
	else
		return false;
}

/*
 * get Options of a Printer
 */
char* PrintImageDialog::getOptionByName(char* pname, char* oname)
{
	int i,j;
	cups_option_t* option;
	for(i = numPrinters, printer = printers; i > 0; i --, printer ++)
		if(strcmp(printer->name, pname) == 0)
			for(j = printer->num_options, option=printer->options; j > 0; j--, option++)
				if(strcmp(option->name, oname) == 0)
					return option->value;
				else
					return (char*)"";
	return (char*)"";
}

/*
 * get Name of the selected Printer
 */
char* PrintImageDialog::getUsed()
{
	return printerName;
}


/*
 * Printer selection from Table
 */
void PrintImageDialog::printer_selected( GtkWidget *clist, gint row, gint column, GdkEventButton *event, gpointer data )
{
    	gchar *text;
	gtk_clist_get_text(GTK_CLIST(clist), row, 0, &text);
	printerName = (char*)text;
}

/*
 * hide Printdialog
 */
void PrintImageDialog::hide()
{
	gtk_widget_hide (printerSelectionDialog);
}

/*
 * get the List of Printers
 */
GtkCList* PrintImageDialog::getPrinterList()
{
	return GTK_CLIST(printerList);
}

/*
 * get the OK-Button
 */
GtkButton* PrintImageDialog::getOkButton()
{
	return GTK_BUTTON(okButton);
}

/*
 * get the Cancel-Button
 */
GtkButton* PrintImageDialog::getCancelButton()
{
	return GTK_BUTTON(cancelButton);
}

/*
 * get the Picturescaling-Value
 */
gint PrintImageDialog::getScaleValue( )
{
	return gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON(scaleSpin) );
}

/*
 * get the Number of Pages to print
 */
gint PrintImageDialog::getPagesValue( )
{
	return gtk_spin_button_get_value_as_int( GTK_SPIN_BUTTON(pagesSpin) );
}

/*
 * get the Scaling-Type
 */
bool PrintImageDialog::getScaling( )
{
	if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(scaleRadio1) ) )
		return true;
	else if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(scaleRadio2) ) )
		return false;
}

/*
 * get the Page-Format
 */
bool PrintImageDialog::getFormat( )
{
	if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(formatRadio1) ) )
		return true;
	else if(gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(formatRadio2) ) )
		return false;
}


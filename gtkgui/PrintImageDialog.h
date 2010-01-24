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

#ifndef PRINTIMAGEDIALOG_H
#define PRINTIMAGEDIALOG_H

#include "OptionMenuBuilder.h"
#include "mygtk.h"
#include "WidgetReadWriter.h"
#include <cups/cups.h>

class PrintImageDialog
{
private:
	PrintImageDialog(const PrintImageDialog &);
	void operator=(const PrintImageDialog &);

	int numPrinters;
	cups_dest_t *printers, *printer;
	int job_id;
public:
	PrintImageDialog();
	
	enum imageType {color, dithered};
	void show(imageType t);
	void hide();

	GtkCList *getPrinterList();

	GtkButton *getOkButton();
	GtkButton *getCancelButton();

	gint getScaleValue();
	gint getPagesValue();

	bool getScaling();
	bool getFormat();

	char* getPrinterName(int destnum);
	int isPrinterDefault(int destnum);
	char* getOptionByName(char* pname, char* option);
	char* getUsed();

	char * generateScript();
private:
	void ditherChanged   (GtkWidget *w);

	GtkWidget *printerSelectionDialog;
	GtkWidget *colorBox;
	GtkWidget *bwBox;

	GtkWidget *ditherBox;
	GtkWidget *ditherBBox;
	GtkWidget *ditherColors;
	GtkWidget *ditherSteps;

	GtkWidget *buttonBox;
	GtkWidget *okButton;
	GtkWidget *cancelButton;

	GtkWidget *printerBox;
	GtkWidget *printerList;
	GtkWidget *adjustBox;

	GtkWidget *scaleLbl;
	GtkWidget *scaleBox;
	GtkObject *scaleAdj;
	GtkWidget *scaleSpin;
	GtkWidget *scaleRadio1;
	GtkWidget *scaleRadio2;
	GSList *scaleGroup;

	GtkWidget *pagesLbl;
	GtkWidget *pagesBox;
	GtkObject *pagesAdj;
	GtkWidget *pagesSpin;

	GtkWidget *formatLbl;
	GtkWidget *formatBox;
	GtkWidget *formatRadio1;
	GtkWidget *formatRadio2;
	GSList *formatGroup;

	imageType type;
	WidgetReadWriter wrw;

	static gint handle_delete (GtkWidget *widget, GdkEvent *event, gpointer data);
	static void toggled_dither_method  (GtkWidget *w, gpointer data);
	static void hide_dither_method     (GtkWidget *w, gpointer data);
	static void show_dither_method     (GtkWidget *w, gpointer data);
	static void printer_selected (GtkWidget *clist, gint row, gint column, GdkEventButton *event, gpointer data);
};

#endif

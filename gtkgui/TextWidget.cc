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
 
 Authors: Sven Sperner
 Changes: Support for Mouse-Scrolling in Script-Window
 Date: Wintersemester 2009/2010
 Last changed: 2010/01/14
 
 **************************************************************************/


#include "TextWidget.h"

void TextWidget::setName (const char *name)
{
	gtk_frame_set_label(GTK_FRAME(frame), name);
}

TextWidget::TextWidget()
{ 
	GtkWidget *vscrollbar;

	hbox = gtk_hbox_new(FALSE,0);
	text = gtk_text_new(0,0);
	gtk_text_set_editable(GTK_TEXT(text), TRUE);
	vscrollbar = gtk_vscrollbar_new (GTK_TEXT(text)->vadj);
	gtk_box_pack_start(GTK_BOX(hbox), text, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(hbox), vscrollbar, FALSE, FALSE, 0);

	frame = gtk_frame_new ("");
	//gtk_container_set_border_width (GTK_CONTAINER(frame), 10);
	gtk_container_set_border_width(GTK_CONTAINER(hbox),5);
	gtk_container_add (GTK_CONTAINER(frame), hbox);
	gtk_widget_set_usize(frame, 450,300);

	gtk_widget_set_events(text, GDK_BUTTON4_MASK | GDK_BUTTON5_MASK);
	gtk_signal_connect(GTK_OBJECT(text), "button_press_event", GTK_SIGNAL_FUNC(handle_scroll_event), this);
}

void TextWidget::setContents (const char *contents)
{
	gtk_text_freeze(GTK_TEXT(text));
	gtk_text_set_point(GTK_TEXT(text), 0);
	gtk_text_forward_delete(GTK_TEXT(text), gtk_text_get_length(GTK_TEXT(text)));
	gtk_text_insert(GTK_TEXT(text),0,0,0,contents,-1);
	gtk_text_thaw(GTK_TEXT(text));
}

void TextWidget::handle_scroll_event( GtkWidget *widget, GdkEventButton *event, gpointer data )
{
	if( event->button == 5 )
		GTK_TEXT(widget)->vadj->value += 10;
	else if( event->button == 4 )
		if(GTK_TEXT(widget)->vadj->value >= 1)
			GTK_TEXT(widget)->vadj->value -= 10;
	gtk_adjustment_value_changed(GTK_TEXT(widget)->vadj);
}


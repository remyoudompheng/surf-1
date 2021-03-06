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


#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include "mygtk.h"

class TextWidget
{
public:
	TextWidget();
	GtkWidget *getContainer()	{ return frame; };
	
	const char *getContents()	{ return gtk_editable_get_chars(GTK_EDITABLE(text),0,-1); };
	void setContents(const char *contents);
	
	void setName (const char *name);

	operator GtkText * () {return GTK_TEXT(text);};

	static void handle_scroll_event(GtkWidget *widget, GdkEventButton *event, gpointer data);
protected:
	GtkWidget *hbox;
	GtkWidget *text;
	GtkWidget *frame;
};

#endif

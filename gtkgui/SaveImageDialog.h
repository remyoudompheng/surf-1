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


#ifndef SAVEIMAGEDIALOG_H
#define SAVEIMAGEDIALOG_H

#include "OptionMenuBuilder.h"
#include "mygtk.h"
#include "WidgetReadWriter.h"

class SaveImageDialog
{
private:
	SaveImageDialog(const SaveImageDialog &);
	void operator=(const SaveImageDialog &);
public:
	SaveImageDialog();
	
	enum imageType {color, dithered};
	void show(imageType t);
	void hide()
		{ gtk_widget_hide (fileselectiondialog);};
	GtkFileSelection *getGtkFileSelection()
		{ return GTK_FILE_SELECTION(fileselectiondialog);}

	char * generateScript();
private:
	void ditherChanged   (GtkWidget *w);

	GtkWidget *fileselectiondialog;
	GtkWidget *colorBox;
	GtkWidget *bwBox;

	GtkWidget *ditherBox;
	GtkWidget *ditherBBox;
	GtkWidget *ditherColors;
	GtkWidget *ditherSteps;

	imageType type;
	WidgetReadWriter wrw;

	static gint handle_delete (GtkWidget *widget, GdkEvent *event, gpointer data);
	static void toggled_dither_method  (GtkWidget *w, gpointer data);
	static void hide_dither_method     (GtkWidget *w, gpointer data);
	static void show_dither_method     (GtkWidget *w, gpointer data);

};

#endif

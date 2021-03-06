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


#ifndef PARAMATERWINDOW_H
#define PARAMATERWINDOW_H

#include <assert.h>

#include <gtk/gtk.h>
#include "SymbolTable.h"
#include "WidgetReadWriter.h"

class ParameterWindow
{
public:
	ParameterWindow() 
		{
			container = 0;
			windowName =0;
		}
	virtual ~ParameterWindow()			{}
	virtual const char *getName()
		{
			assert(windowName);
			return windowName;
		}

	virtual GtkWidget *getContainer()
		{
			assert(container);
			return container;
		}

	virtual void writeSymbols (SymbolTable &st)	{}
	virtual void readSymbols (SymbolTable &st)	{}

	void controlWidget (GtkWidget *widget, const char *variable_name)
		{ wrw.addWidget(widget, variable_name); }

	void wrw_writeSymbols(SymbolTable &st)
		{ wrw.writeSymbols(st); }
	void wrw_readSymbols (SymbolTable &st)
		{ wrw.readSymbols(st); }

protected:
	GtkWidget *container;
	const char *windowName;
private:
	WidgetReadWriter wrw;
};

#endif

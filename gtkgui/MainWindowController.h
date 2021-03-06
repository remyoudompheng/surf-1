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
    Changes: enable support for Printing via CUPS
    Date: Wintersemester 2009/2010
    Last changed: 2010/01/14

**************************************************************************/

#ifndef MAINWINDOWCONTROLLER_H
#define MAINWINDOWCONTROLLER_H

#if defined(HAVE_LIBCUPS)
#include <cups/cups.h>
#include "PrintImageDialog.h"
#endif
#include "mygtk.h"
#include "DrawingArea.h"

#include "TextWidget.h"
#include "ColorWindow.h"
#include "Document.h"
#include "ConfigurationWindow.h"
#include "WidgetReadWriter.h"
#include "SaveImageDialog.h"
#include "ProgressDialog.h"

enum SaveButtonType {
	Color, Dithered
};

class MainWindowController : private DocumentListener
{
private:
	MainWindowController (const MainWindowController &);
	void operator=(const MainWindowController &);

public:
	MainWindowController();
	~MainWindowController();


	void allowScriptExecution(bool val);
	void showError (Document *doc, int error_begin, int error_end, const char *errorString);
	void editDocument (Document *doc);
	VOIDCALL(executeScript, MainWindowController);
	void show();
	void quit();	
	void toggleDisplayedState();
	
	void enableSaveButton(SaveButtonType which);
	
protected:
	MENUCALLBACK(showAbout, MainWindowController);
	void showAbout();

	MENUCALLBACK(quit, MainWindowController);

	
	MENUCALLBACK(newDocument, MainWindowController);
	void newDocument();

	MENUCALLBACK(loadScript, MainWindowController);
	MENUCALLBACK(saveScript, MainWindowController);
#if defined(HAVE_LIBCUPS)
//Menuentrys for Printing
	MENUCALLBACK(printColorImage, MainWindowController);
	MENUCALLBACK(printDitheredImage, MainWindowController);
#endif
	MENUCALLBACK(executeScript, MainWindowController);
	MENUCALLBACK(drawSurface, MainWindowController);
	MENUCALLBACK(ditherSurface, MainWindowController);
	MENUCALLBACK(drawCurve, MainWindowController);
	MENUCALLBACK(ditherCurve, MainWindowController);
	MENUCALLBACK(configuration, MainWindowController);
	MENUCALLBACK(newColorWindow, MainWindowController);
	MENUCALLBACK(saveColorImage, MainWindowController);
	MENUCALLBACK(newDitherWindow, MainWindowController);
	MENUCALLBACK(saveDitheredImage, MainWindowController);

	VOIDCALL(saveScript, MainWindowController);

	MENUCALLBACK(saveScriptAs, MainWindowController);
	void saveScriptAs();



	VOIDCALL(drawSurface, MainWindowController);
	VOIDCALL(ditherSurface, MainWindowController);

	VOIDCALL(drawCurve, MainWindowController);
	VOIDCALL(ditherCurve, MainWindowController);


	VOIDCALL(configuration, MainWindowController)
		{
			cw.show();
		}




	VOIDCALL(loadScript,MainWindowController);



	VOIDCALL(newColorWindow, MainWindowController)
		{
			colorWindow->unlock();
			colorWindow = new ColorWindow(this, true);
			colorWindow->show();
		}

	VOIDCALL(newDitherWindow, MainWindowController)
		{
			bitmapWindow->unlock();
			bitmapWindow = new ColorWindow(this, false);
			bitmapWindow->show();
		}

	VOIDCALL(saveDitheredImage, MainWindowController);
	VOIDCALL(saveColorImage, MainWindowController);
	VOIDCALL(saveImageDialogOkay, MainWindowController);
	VOIDCALL(saveImageDialogCancel, MainWindowController);

#if defined(HAVE_LIBCUPS)
//Signalconnections for Printing
	VOIDCALL(printDitheredImage, MainWindowController);
	VOIDCALL(printColorImage, MainWindowController);
	VOIDCALL(printImageDialogOkay, MainWindowController);
	VOIDCALL(printImageDialogCancel, MainWindowController);
#endif

	VOIDCALL(destroy, MainWindowController);

	VOIDCALL(fileSelected, MainWindowController);
	VOIDCALL(fileSelectionCancelled, MainWindowController);

	static gint fileSelectionDelete (GtkWidget *widget, GdkEvent *event, gpointer data);

protected:
	GtkFileSelection *filesel;
	
	GtkWidget *window;
	GtkWidget *mainBox; /* hbox */
	TextWidget tw;
	
	GtkWidget *frame;
	GtkWidget *buttons;
	GtkWidget *b1;
	GtkWidget *b2;
	GtkWidget *loadScriptButton;
	GtkWidget *testButton;

  	GtkWidget *executeScriptButton;
  	GtkWidget *drawSurfaceButton;
	GtkWidget *ditherSurfaceButton;
	GtkWidget *drawCurveButton;
	GtkWidget *ditherCurveButton;
	GtkWidget* colorSaveButton;
	GtkWidget* ditheredSaveButton;
	
	ColorWindow *colorWindow;
	ColorWindow *bitmapWindow;

	GtkWidget *loadedScripts;
	GtkWidget* saveColor_MenuItem;
	GtkWidget* saveDithered_MenuItem;
	GtkWidget* executeScript_MenuItem;
	GtkWidget* drawSurface_MenuItem;
	GtkWidget* ditherSurface_MenuItem;
	GtkWidget* drawCurve_MenuItem;
	GtkWidget* ditherCurve_MenuItem;
	ConfigurationWindow cw;

	Document *actualDocument;
	
	Document *docToSave;
	

	GtkWidget * previewButtons[3];
	bool displayedState;

	bool colorSaveButtonState;
	bool ditheredSaveButtonState;
	
private:
	WidgetReadWriter wrw;
	SaveImageDialog saveImageDialog;
#if defined(HAVE_LIBCUPS)
//Objects/Variables for Printing
	PrintImageDialog printImageDialog;
	cups_dest_t *myPrinters, *myPrinter;
	int numMyPrinters;
#endif

	ProgressDialog progress;

	void addedDocument (Document *doc);


	bool mayClose();
	

	void internalExecuteScript (const char *before, const char *user, const char *after, bool run_commands);



	typedef void (*methodType)(MainWindowController *);
	GtkWidget *addCommandButton (const char *command, const char *tip=0);
	void addCommandSeparator();

	static void selectedDocument (GtkWidget *widget, gpointer data);

	static gint handle_delete_event (GtkWidget *widget, GdkEvent *event, gpointer data);

	static void previewToggled(GtkWidget *widget, gpointer data);
};

#endif

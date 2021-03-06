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


#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <stdlib.h>
#include <glib.h>

class Document;

class DocumentListener
{
public:
	virtual ~DocumentListener();
	DocumentListener();

	virtual void addedDocument (Document *);
	virtual void removedDocument (Document *);
	virtual void changedName (Document *);
	

	static void invokeMethodOnAllListeners (void (DocumentListener::*method)(Document *), Document *doc);

};


class Document 
{
private:
	Document (Document &);
	void operator=(const Document &);
	
	Document();
	~Document();

	
public:
	static char *readFile (const char *name);
	static Document *loadDocument (const char *name);
	static Document *getDocumentWithName (const char *name);
	
	static Document *newUnnamed ();

	static int countChangedDocuments();

	static void freeAllDocuments();


	void setName (const char *name);
	void setContents (const char *contents);

	const char *getName () const;
	const char *getContents () const
		{ return text; };

	bool isChanged () const 
		{ return changed; };

	void save ();
	void saveAs (const char *name);
	bool needsName () const;
private:
	char *text;
	char *name;
	bool changed;
	int unnamedNumber;
	static int unnamedCount;
	
	friend class Dummy;
};



#endif

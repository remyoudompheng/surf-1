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

// ============================================================================
// File      ps.cc
// Author:   Stephan Endrass
// Address:  endrass@mi.uni-erlangen.de
// Date:     3.2.95
// ============================================================================

/**************************************************************************
 Projectteam 'Qualifizierung und Weiterentwicklung eines Software-Pakets
 zur Darstellung reell-algebraischer Kurven und Flächen'
 from Fachhochschule Frankfurt am Main (University of Applied Sciences)
 
 Authors: Marcus Scherer, Jonas Heil
 Changes: add support for saving color ps and pdf
 Date: Wintersemester 2009/2010
 Last changed: 2010/01/14
 
 **************************************************************************/

#include <sys/param.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <netdb.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <string.h>
#include <iostream>

#include <sys/types.h>
#include <sys/wait.h>


#include "bit_buffer.h"
#include "RgbBuffer.h"
#include "Misc.h"

#ifdef NO_GETHOSTNAME_PROTO
extern "C" int gethostname (char *, int);
#endif

// ----------------------------------------------------------------------------
//  Produce postscript output
// ----------------------------------------------------------------------------

bool psprint (bit_buffer &pixel, FILE *fp_ps, int resolution)
{
	int paper_width = pixel.getWidth();
	int paper_height= pixel.getHeight();

	int     px,py,byte;

	// --------------------------------------------------
	//  Bounding box: center by default, assume a4 paper
	// --------------------------------------------------

	int     width  = ( paper_width*72 )/resolution;
	int     height = ( paper_height*72 )/resolution;
	int     x1 = (595 - width)/2;
	int     x2 = width + x1;
	int     y1 = (839 - height)/2;
	int     y2 = height + y1;

	// --------------------
	//  User name and info
	// --------------------

	struct  passwd  *passwd_user;

	passwd_user = getpwuid( getuid( ) );
     
	char    *name_user = passwd_user->pw_name;
	char    *info_user = passwd_user->pw_gecos;

	// ----------
	//  Hostname
	// ----------

	char    hostname[MAXHOSTNAMELEN];

	gethostname( hostname,MAXHOSTNAMELEN );

	// ---------------
	//  Time and date
	// ---------------

	time_t  time_local;
	char    *the_time;

	time_local = time( NULL );
	the_time   = ctime( &time_local );

	// ---------------
	//  Picture title
	// ---------------

	const char    *title = "algebraic surface (dithered image)";


	// -----------------
	//  Number of pages
	// -----------------

	int     pages = 1;
    
	fprintf( fp_ps,"%%!PS-Adobe-1.0\n" );
	fprintf( fp_ps,"%%%%BoundingBox: %d %d %d %d\n",x1-1,y1-1,x2+1,y2+1 );
	fprintf( fp_ps,"%%%%Creator: %s:%s (%s)\n",hostname,name_user,info_user );
	fprintf( fp_ps,"%%%%Title: %s\n",title );
	fprintf( fp_ps,"%%%%CreationDate: %s",the_time );
	fprintf( fp_ps,"%%%%EndComments\n" );
	fprintf( fp_ps,"%%%%Pages: %d\n",pages );
	fprintf( fp_ps,"%%%%EndProlog\n" );
	fprintf( fp_ps,"%%%%Page: 1 1\n" );
	fprintf( fp_ps,"\n" );
	fprintf( fp_ps,"/bitdump %% stk: width, height, iscale\n" );
	fprintf( fp_ps,"%% dump a bit image with lower left corner at current origin,\n" );
	fprintf( fp_ps,"%% scaling by iscale (iscale=1 means 1/300 inch per pixel)\n" );
	fprintf( fp_ps,"{\n" );
	fprintf( fp_ps,"        %% read arguments\n" );
	fprintf( fp_ps,"        /iscale exch def\n" );
	fprintf( fp_ps,"        /height exch def\n" );
	fprintf( fp_ps,"        /width exch def\n" );
	fprintf( fp_ps,"\n" );
	fprintf( fp_ps,"        %% scale appropriately\n" );
	fprintf( fp_ps,"        width iscale mul height iscale mul scale\n" );
	fprintf( fp_ps,"\n" );
	fprintf( fp_ps,"        %% allocate space for one scanlne of input\n" );
	fprintf( fp_ps,"        /picstr %% picstr holds one scan line\n" );
	fprintf( fp_ps,"                width 7 add 8 idiv %% width of image in bytes = ceiling( width/8)\n" );
	fprintf( fp_ps,"                string\n" );
	fprintf( fp_ps,"                def\n" );
	fprintf( fp_ps,"\n" );
	fprintf( fp_ps,"        %% read and dump the image\n" );
	fprintf( fp_ps,"        width height 1 [width 0 0 height neg 0 height]\n" );
	fprintf( fp_ps,"        { currentfile picstr readhexstring pop }\n" );
	fprintf( fp_ps,"        image\n" );
	fprintf( fp_ps,"} def\n" );
	fprintf( fp_ps,"72 %d div dup scale\n",resolution );
	fprintf( fp_ps,"%d %d translate\n",x1*resolution/72,y1*resolution/72 );
	fprintf( fp_ps,"%d %d 1 bitdump\n",paper_width,paper_height );
	
	for( py = 0; py < paper_height; py++ ) {
		for( px = 0; px < paper_width; px += 8 ) {
			byte = 255-pixel.getByte(px,py);
			fprintf( fp_ps,"%.2x",byte );
		}
		fprintf( fp_ps,"\n" );
	}
	fprintf( fp_ps,"showpage\n" );
	fprintf( fp_ps,"%%%%Trailer\n" );
	fprintf( fp_ps,"end\n" );
	fprintf( fp_ps,"%%%%EOF" );

	return true;
}

bool psprint_color (RgbBuffer &pixel, FILE *fp_ps, int resolution)
{
	int paper_width = pixel.getWidth();
	int paper_height= pixel.getHeight();

	int     px,py,byte;

	// --------------------------------------------------
	//  Bounding box: center by default, assume a4 paper
	// --------------------------------------------------

	int     width  = ( paper_width*72 )/resolution;
	int     height = ( paper_height*72 )/resolution;
	int     x1 = (595 - width)/2;
	int     x2 = width + x1;
	int     y1 = (839 - height)/2;
	int     y2 = height + y1;

	// --------------------
	//  User name and info
	// --------------------

	struct  passwd  *passwd_user;

	passwd_user = getpwuid( getuid( ) );
     
	char    *name_user = passwd_user->pw_name;
	char    *info_user = passwd_user->pw_gecos;

	// ----------
	//  Hostname
	// ----------

	char    hostname[MAXHOSTNAMELEN];

	gethostname( hostname,MAXHOSTNAMELEN );

	// ---------------
	//  Time and date
	// ---------------

	time_t  time_local;
	char    *the_time;

	time_local = time( NULL );
	the_time   = ctime( &time_local );

	// ---------------
	//  Picture title
	// ---------------

	const char    *title = "algebraic surface (colored image)";


	// -----------------
	//  Number of pages
	// -----------------

	int     pages = 1;
    
	fprintf( fp_ps,"%%!PS-Adobe-1.0\n" );
	fprintf( fp_ps,"%%%%BoundingBox: %d %d %d %d\n",x1-1,y1-1,x2+1,y2+1 );
	fprintf( fp_ps,"%%%%Creator: %s:%s (%s)\n",hostname,name_user,info_user );
	fprintf( fp_ps,"%%%%Title: %s\n",title );
	fprintf( fp_ps,"%%%%CreationDate: %s",the_time );
	fprintf( fp_ps,"%%%%EndComments\n" );
	fprintf( fp_ps,"%%%%Pages: %d\n",pages );
	fprintf( fp_ps,"%%%%EndProlog\n" );
	fprintf( fp_ps,"%%%%Page: 1 1\n" );
	fprintf( fp_ps,"\n" );
	fprintf( fp_ps,"/bitdump %% stk: width, height, iscale\n" );
	fprintf( fp_ps,"%% dump a bit image with lower left corner at current origin,\n" );
	fprintf( fp_ps,"%% scaling by iscale (iscale=1 means 1/300 inch per pixel)\n" );
	fprintf( fp_ps,"{\n" );
	fprintf( fp_ps,"        %% read arguments\n" );
	fprintf( fp_ps,"        /iscale exch def\n" );
	fprintf( fp_ps,"        /height exch def\n" );
	fprintf( fp_ps,"        /width exch def\n" );
	fprintf( fp_ps,"\n" );
	fprintf( fp_ps,"        %% scale appropriately\n" );
	fprintf( fp_ps,"        width iscale mul height iscale mul scale\n" );
	fprintf( fp_ps,"\n" );
	fprintf( fp_ps,"        %% allocate space for one scanlne of input\n" );
	fprintf( fp_ps,"        /picstr %% picstr holds one scan line\n" );
	fprintf( fp_ps,"                width 7 add 8 idiv %% width of image in bytes = ceiling( width/8)\n" );
	fprintf( fp_ps,"                string\n" );
	fprintf( fp_ps,"                def\n" );
	fprintf( fp_ps,"\n" );
	fprintf( fp_ps,"        %% read and dump the image\n" );
	fprintf( fp_ps,"        width height 8 [width 0 0 height neg 0 height]\n" );
	fprintf( fp_ps,"        { currentfile picstr readhexstring pop }\n" );
	fprintf( fp_ps,"		false 3\n");
	fprintf( fp_ps,"        colorimage\n" );
	fprintf( fp_ps,"} def\n" );
	fprintf( fp_ps,"72 %d div dup scale\n",resolution );
	fprintf( fp_ps,"%d %d translate\n",x1*resolution/72,y1*resolution/72 );
	fprintf( fp_ps,"%d %d 1 bitdump\n",paper_width,paper_height );
	
	for( py = 0; py < paper_height; py++ ) {
		for( px = 0; px < paper_width; px++ ) {
			byte = pixel.Get_one(px,py,0);
			fprintf( fp_ps,"%.2x",byte );
			byte = pixel.Get_one(px,py,1);
			fprintf( fp_ps,"%.2x",byte );
			byte = pixel.Get_one(px,py,2);
			fprintf( fp_ps,"%.2x",byte );
		}
		fprintf( fp_ps,"\n" );
	}
	fprintf( fp_ps,"showpage\n" );
	fprintf( fp_ps,"%%%%Trailer\n" );
	fprintf( fp_ps,"end\n" );
	fprintf( fp_ps,"%%%%EOF" );

	return true;
}

bool pdfprint (class bit_buffer &pixel, FILE *psfile, int resolution, const char *fileloc) {

	printf("DPI: %i\n", resolution); 
	psprint(pixel, psfile, resolution);	
	
	int status;
	pid_t pID = fork();
	
	if (pID == 0) 	 {
		execl("/usr/bin/ps2pdf", "/usr/bin/ps2pdf", fileloc, "temp.pdf",  (char *) 0);
		_exit (EXIT_FAILURE);
	}
	if (pID > 0) 
	{
		waitpid(pID, &status, 0);	
		pid_t pID2 = fork();
		if (pID2 == 0) 	{
			execl("/bin/mv", "/bin/mv", "temp.pdf", fileloc,  (char *) 0);
			_exit (EXIT_FAILURE);
		}
	}
	return true;
	
}


bool pdfprint_color (class RgbBuffer &pixel, FILE *psfile, int resolution,const char *fileloc) {
	
	
	psprint_color(pixel, psfile, resolution);	
	
	int status;
	pid_t pID = fork();
	
	if (pID == 0) 	 {
		execl("/usr/bin/ps2pdf", "/usr/bin/ps2pdf", fileloc, "temp.pdf",  (char *) 0);
		_exit (EXIT_FAILURE);
	}
	if (pID > 0) 
	{
		waitpid(pID, &status, 0);	
		pid_t pID2 = fork();
		if (pID2 == 0) 	{
			execl("/bin/mv", "/bin/mv", "temp.pdf", fileloc,  (char *) 0);
			_exit (EXIT_FAILURE);
		}
	}
	return true;
}
// ============================================================================
// End of ps.cc
// ============================================================================


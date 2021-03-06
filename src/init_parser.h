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

// ===========================================================================
// File:     init_parser.cc
// Author:   Stephan Endrass
// Address:  endrass@mi.uni-erlangen.de
// Date:     3.2.95
// ============================================================================

/**************************************************************************
 Projectteam 'Qualifizierung und Weiterentwicklung eines Software-Pakets
 zur Darstellung reell-algebraischer Kurven und Flächen'
 from Fachhochschule Frankfurt am Main (University of Applied Sciences)
 
 Authors: Marcus Scherer, Jonas Heil
 Changes: add support for saving color ps,eps and pdf
 Date: Wintersemester 2009/2010
 Last changed: 2010/01/14
 
 **************************************************************************/

// ----------------------------------------------------------------------------
//  Function prototypes
// ----------------------------------------------------------------------------

void    init_surface_main_commands ( void );
void    init_surface_main_variables( void );

extern void addCommand (const char *name, void (*func) (void));
extern void addConstant (const char *name, const int *ptr);
extern void addConstant (const char *name, double *ptr);
extern void addNumber (const char *name, int *ptr);
extern void addNumber (const char *name, double *ptr);

extern const char *getColorSliderPicString (int surfaceNr, bool inside, int color);
extern const char *getLightSliderPicString (int lightNr, int color);


extern double sym_cut_distance;


// ============================================================================
// End of init_parser.cc
// ============================================================================

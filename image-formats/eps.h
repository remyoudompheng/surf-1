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
// File      eps.h
// Author:   Stephan Endrass
// Address:  endrass@mi.uni-erlangen.de
// Date:     3.2.95
// ============================================================================

/**************************************************************************
 Projectteam 'Qualifizierung und Weiterentwicklung eines Software-Pakets
 zur Darstellung reell-algebraischer Kurven und Flächen'
 from Fachhochschule Frankfurt am Main (University of Applied Sciences)
 
 Authors: Marcus Scherer, Jonas Heil
 Changes: add support for saving color eps 
 Date: Wintersemester 2009/2010
 Last changed: 2010/01/14
 
 **************************************************************************/
#ifndef EPS_H
#define EPS_H

extern bool epsprint (class bit_buffer &pixel, FILE *epsfile, int resolution);

extern bool epsprint_color (class RgbBuffer &pixel, FILE *epsfile, int resolution);

#endif  /* EPS_H */

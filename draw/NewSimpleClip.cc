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


#include "NewSimpleClip.h"

#include "gui_config.h"

void NewSimpleClip::init()
{
	cb = clip_numeric.clip_back;
	cf = clip_numeric.clip_front;

	sz = position_numeric.spectator_z;

	cx = clip_numeric.center_x;
	cy = clip_numeric.center_y;
	cz = clip_numeric.center_z;
	r  = clip_numeric.radius;
	d1 = sz - cz;

	szsq = sz*sz;
	cxsq = cx*cx;
	cysq = cy*cy;
	czsq = cz*cz;
	rsq  = r*r;
	d1sq = d1*d1;
}

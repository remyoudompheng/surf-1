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


#include <stdlib.h>
#include <assert.h>

#include "RgbBuffer.h"
#include "float_buffer.h"

#include "stop.h"

void copy_rgb_to_float_curve (RgbBuffer &intensity, float_buffer& gray)
{
	assert(intensity.getWidth()==gray.getWidth());
	assert(intensity.getHeight()==gray.getHeight());
	
	int i,j;

	for( i = 0; i < intensity.getHeight() && !stop; i++ ) {
		for(  j = 0; j < intensity.getWidth(); j++ ) {
			gray.Set(j,i,( intensity.GetTag( j,i,DATABIT ) ? 0.0 : 1.0 ) );
		}
	}
}

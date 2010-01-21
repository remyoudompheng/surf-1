/*
 *   surf - visualizing algebraic curves and algebraic surfaces
 *   Author: Rémy Oudompheng
 *   Copyright (C) 2010 Rémy Oudompheng
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

using namespace std;

#include <gtkmm.h>
#include "UIDefinition.h"

int
main (int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);
  Glib::RefPtr<Gtk::Builder> refGlade = Gtk::Builder::create();
  refGlade->add_from_string(gtk2gui_xml);

  Gtk::Window* window;
  refGlade->get_widget("window_main", window);
  window->show_all();

  kit.run();

  return 0;
}

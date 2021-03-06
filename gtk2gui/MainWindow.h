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

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtkmm.h>

class MainWindow : public Gtk::Window
{
 public:
  MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
  virtual ~MainWindow();

 protected:
  Glib::RefPtr<Gtk::Builder> uidef;

  void _on_new_activate();
  void _on_open_activate();
  void _on_save_activate();
  void _on_save_as_activate();
  void _on_quit_activate();
};

#endif //!MAIN_WINDOW_H

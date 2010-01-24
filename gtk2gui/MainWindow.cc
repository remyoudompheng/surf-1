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

#include "MainWindow.h"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
  : Gtk::Window(cobject),
    uidef(refGlade)
{
  // File Menu item callbacks
  Gtk::MenuItem* mi_new = 0;
  Gtk::MenuItem* mi_open = 0;
  Gtk::MenuItem* mi_save = 0;
  Gtk::MenuItem* mi_save_as = 0;
  Gtk::MenuItem* mi_quit = 0;
  uidef->get_widget("mi_new", mi_new);
  uidef->get_widget("mi_open", mi_open);
  uidef->get_widget("mi_save", mi_save);
  uidef->get_widget("mi_saveas", mi_save_as);
  uidef->get_widget("mi_quit", mi_quit);

  mi_new->signal_activate().connect( sigc::mem_fun(*this, &MainWindow::_on_new_activate) );
  mi_open->signal_activate().connect( sigc::mem_fun(*this, &MainWindow::_on_open_activate) );
  mi_save->signal_activate().connect( sigc::mem_fun(*this, &MainWindow::_on_save_activate) );
  mi_save_as->signal_activate().connect( sigc::mem_fun(*this, &MainWindow::_on_save_as_activate) );
  mi_quit->signal_activate().connect( sigc::mem_fun(*this, &MainWindow::_on_quit_activate) );
}

MainWindow::~MainWindow()
{
}

// File Menu item callbacks
void MainWindow::_on_new_activate() {}
void MainWindow::_on_open_activate() {}
void MainWindow::_on_save_activate() {}
void MainWindow::_on_save_as_activate() {}

void MainWindow::_on_quit_activate()
{
  Gtk::Main::quit();
}

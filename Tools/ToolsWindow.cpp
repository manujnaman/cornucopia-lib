/*--
    ToolsWindow.cpp  

    This file is part of the Cornucopia curve sketching library.
    Copyright (C) 2010 Ilya Baran (ibaran@mit.edu)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "ToolsWindow.h"
#include "AddTool.h"
#include "FormatTool.h"

#include <QAction>
#include <QMenuBar>

ToolsWindow::ToolsWindow()
{
    addTool(new AddTool(this));
    addTool(new FormatTool(this));
}

void ToolsWindow::addTool(Tool *tool)
{
    QAction *action = new QAction(tool->getName(), this);
    connect(action, SIGNAL(triggered()), tool, SLOT(execute()));

    menuBar()->addAction(action);
}

#include "ToolsWindow.moc"
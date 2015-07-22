/**
 * @file
 * @author shrek0 (shrek0.tk@gmail.com)
 * @class
 * @section LICENSE
 *
 * Snaking copyright (C) 2015 shrek0
 *
 * Snaking is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Snaking is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 */

#include "screen.h"

#include <ncurses.h>

#include <iostream>

Screen::Screen() {
    ::initscr();
    ::noecho();
    ::keypad(stdscr, TRUE);

    updateScreenSize();
}

Screen::~Screen()
{
    ::endwin();
}

void Screen::clear()
{
    ::clear();
}

void Screen::refresh()
{
    ::refresh();
}

void Screen::putchar(CharType charType, Screen::ScreenPosition x, Screen::ScreenPosition y)
{
    ::mvprintw(y, x, "%c", charType);
}

void Screen::print(const PrintableObject &object) {
    for(auto character : object.toList())
    {
        putchar(character.getChar(), character.x, character.y);
    }
}

void Screen::updateScreenSize() {
    y = getmaxy(stdscr);
    x = getmaxx(stdscr);
}


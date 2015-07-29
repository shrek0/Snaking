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

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <cstdint>

#include "printableobject.h"

#include <iostream>

class Screen
{
public:
    Screen();
    ~Screen();

    typedef size_t ScreenPosition;
    typedef size_t ScreenSize;
    typedef PrintableObject::CharType CharType;

    void clear();
    void refresh();

    ScreenSize getSizeX() { return x; }
    ScreenSize getSizeY() { return y; }

    void printf(Screen::ScreenPosition x, Screen::ScreenPosition y, const char *format, ...);
    void putchar(CharType charType, Screen::ScreenPosition x, Screen::ScreenPosition y);
    void print(const PrintableObject &object);

    void updateScreenSize();

private:
    ScreenSize x;
    ScreenSize y;


};

#endif // SCREEN_H

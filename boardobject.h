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

#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H

#include "printableobject.h"

class BoardObject : public PrintableObject
{
public:
//    BoardObject(const std::string &string);
    BoardObject(CharType c);
//    BoardObject(const CharType *charArray);
    BoardObject() { }

    enum ObjectType{
        None,
        Snake,
        Food,
        Wall
    };

    BoardObject(ObjectType objectType)
        : type(objectType)
    { }

    ObjectType getType() const
    {
        return type;
    }

protected:
    ObjectType type;
};

#endif // BOARDOBJECT_H

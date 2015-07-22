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

#ifndef PRINTABLEOBJECT_H
#define PRINTABLEOBJECT_H

#include "character.h"

#include <string>
#include <list>

class PrintableObject
{
public:
    typedef Character::CharType CharType;
    typedef std::list<Character>::size_type SizeType;

    PrintableObject() { }
    PrintableObject(CharType c) { fromChar(c); }
//    PrintableObject(const CharType *string) { fromCharArray(string); }

//    void fromString(const std::string &string);
//    void fromCharArray(const CharType *string) { fromString(std::string(string)); }
    void fromChar(const Character &c) { charactersList.clear();  charactersList.push_front(c); }

    const std::list<Character> &toList() const{ return charactersList; }
    std::list<Character> &getList() { return charactersList; }

    enum ObjectColor{
        Black,
        Green,
        Yellow,
        Blue,
        Megenta,
        Cyan,
        White
    };

    ObjectColor getColor() const{ return color; }
    SizeType getSize() { return charactersList.size(); }

private:
    std::list<Character> charactersList;
    ObjectColor color;

};

#endif // PRINTABLEOBJECT_H

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

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <curses.h>
#include <pthread.h>

#include "character.h"

class Keyboard
{
public:
    typedef Character::CharType CharType;

    Keyboard();
    ~Keyboard();

    bool isWaitingChar() { return bIsWaitingChar; }

    int getchar() { int c = getch(); bIsWaitingChar=false; return c; }

    enum Direction{
        Up = KEY_UP,
        Down = KEY_DOWN,
        Right = KEY_RIGHT,
        Left = KEY_LEFT
    };
private:
    bool bIsWaitingChar = false;
    pthread_t thread;

    void createThread();

    static void *thread_main(void *args);
};

#endif // KEYBOARD_H

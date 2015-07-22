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

#include "keyboard.h"

#include <pthread.h>
#include <unistd.h>

Keyboard::Keyboard()
{
    createThread();
}

Keyboard::~Keyboard() {
    ::pthread_cancel(thread);
    ::pthread_join(thread, NULL);
}

void Keyboard::createThread()
{
     pthread_create(&thread, NULL, Keyboard::thread_main, &bIsWaitingChar);
}

void *Keyboard::thread_main(void *args) {
    bool *isWaitingChar = reinterpret_cast<bool*>(args);
    int c = 0;

    while(true) {
        pthread_testcancel();

        if(*isWaitingChar == true) {
            ::usleep(1000);
            continue;
        }

        c = getch();
        ungetch(c);
        *isWaitingChar = true;
    }
}


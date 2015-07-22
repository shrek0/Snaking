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

#ifndef SNAKE_H
#define SNAKE_H

#include "boardobject.h"
#include "board.h"

class Snake : public BoardObject
{
public:
    static char snakeChar;

    Snake(Board &board);

    enum Direction{
        Up,
        Down,
        Right,
        Left
    };

    void grow(size_t s=1);

    void move(Direction direction);
    void step();

    /**
     * @brief generate generate snakeList into MultipleLinesBoardObject
     */
    void generate();

    const size_t initalSize = 5;

    const Point &getHeadPoint();

private:
    void removeLastPart();
    void addHead(const Point &point);
    void addPartAtHead(Direction direciton);

    Direction direction;
    Board &board;
};

#endif // SNAKE_H

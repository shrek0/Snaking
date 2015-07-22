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

#ifndef BOARD_H
#define BOARD_H

#include "screen.h"
#include "boardobject.h"
#include "multiplelinesboardobject.h"

#include <unordered_map>

class Board
{
public:
    typedef Screen::ScreenSize BoardSize;
    typedef Screen::ScreenPosition BoardPosition;

    Board(Screen &screen);

    void render();

//    struct Point {
//        bool operator < (const Point &point) const{ return x < point.x && y < point.y; }
//        BoardPosition x;
//        BoardPosition y;
//    };

//    void setMultipleLinesBoardObject(const MultipleLinesBoardObject &multipleLinesBoardObject);

    void setBoardObject(const BoardObject &boardObject)
    {
        board[boardObject.toList().front()] = boardObject;
    }

    const BoardObject &getBoardObjectByPoint(const Point &point) const
    {
        return board.at(point);
    }

    bool isSomethingOnPoint(const Point &point) const
    {
        return board.find(point) != board.cend();
    }

    void removeBoardObjectOnPoint(const Point &point)
    {
        board.erase(point);
    };

    void clear() { board.clear(); screen.clear(); }

    BoardSize getX() { return screen.getSizeX(); }
    BoardSize getY() { return screen.getSizeY(); }

private:
    std::unordered_map<Point, BoardObject> board;

    Screen &screen;
};

#endif // BOARD_H

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

#include "snake.h"

char Snake::snakeChar = '*';

Snake::Snake(Board &board) : BoardObject(BoardObject::Snake), board(board) {
    for(std::list<Point>::size_type i = 0; i < initalSize; i++)
        getList().push_front(Character(snakeChar, i ,0));
}

void Snake::grow(size_t s) {
    for(size_t i = 0; i < s; ++i)
        addPartAtHead(this->direction);
}

void Snake::move(Snake::Direction direction)
{
    this->direction = direction;
}

void Snake::step() {
    addPartAtHead(direction);

    removeLastPart();
}

void Snake::generate() {
//    list.clear();

//    x = board.getX();
//    y = board.getY();

//    // Find the correct x and y.
//    for(auto point : snakeList) {
//        if(point.x < x)
//            x = point.x;
//        if(point.y < y)
//            y = point.y;
//    }

//    for(auto point : snakeList) {
//        Point relativePoint(point.x-x, point.y-y);

//        // We don't have enugth lines.
//        if(list.size() <= relativePoint.x)
//            list.resize(relativePoint.x+1);

//        std::string &string = list[relativePoint.x].boardObject.getString();

//        if(string.size() <= relativePoint.y)
//            string.resize(relativePoint.y+1, snakeChar);

//        string[relativePoint.y] = snakeChar;
//        list[relativePoint.x].point = Point(0, relativePoint.y);
//    }
}

void Snake::removeLastPart() {
    if(getList().size() > 0)
        getList().pop_back();
}

void Snake::addHead(const Point &point)
{
    getList().push_front(Character(snakeChar, point.x, point.y));
}

const Point &Snake::getHeadPoint()
{
    return getList().front();
}

void Snake::addPartAtHead(Snake::Direction direciton) {
    Point point(0, 0);

    switch(direciton) {
    case Left:
        point = Point(getHeadPoint().x-1, getHeadPoint().y);
        break;
    case Right:
        point = Point(getHeadPoint().x+1, getHeadPoint().y);
        break;
    case Down:
        point = Point(getHeadPoint().x, getHeadPoint().y+1);
        break;
    case Up:
        point = Point(getHeadPoint().x, getHeadPoint().y-1);
        break;
    default:
        break;
    }

    if(point.x == board.getX())
        point.x = 0;
    else if(point.y == board.getY())
        point.y = 0;
    if(point.x == static_cast<Point::PointPosition>(-1))
        point.x = board.getX()-1;
    else if(point.y == static_cast<Point::PointPosition>(-1))
        point.y = board.getY()-1;

    addHead(point);
}


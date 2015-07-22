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
#include "board.h"
#include "keyboard.h"
#include "food.h"

#include <unistd.h>

#include <cstring>

int main(int argc, char *argv[]) {
    Screen screen;
    Board board(screen);
    Snake snake(board);
    Keyboard keyboard;
    Food food(12,
              14);

    snake.move(Snake::Right);

    while(true) {
        board.clear();
        board.setBoardObject(food);
        board.setBoardObject(snake);
        board.render();

        if(keyboard.isWaitingChar()) {
            switch(keyboard.getchar()) {
            case Keyboard::Up:
                snake.move(Snake::Up);
                break;
            case Keyboard::Down:
                snake.move(Snake::Down);
                break;
            case Keyboard::Right:
                snake.move(Snake::Right);
                break;
            case Keyboard::Left:
                snake.move(Snake::Left);
                break;
            case 'q':
                return 0;
                break;
            }
        }

        snake.step();

//        if(board.isSomethingOnPoint(snake.getHeadPoint())) {
//                std::cout << "isSomething!" << std::endl;

//                const BoardObject &boardObject = board.getBoardObjectByPoint(snake.getHeadPoint());

//                switch(boardObject.getType()) {
//                case BoardObject::Food:
//                    std::cout << "Food";
//                    break;
//                case BoardObject::Snake:
//                    std::cout << "Snake";
//                    break;
//                case BoardObject::Wall:
//                    std::cout << "Wall";
//                default:
//                    std::cout << "None";
//                }

//                std::cout << std::endl;
//        }

        if(board.isSomethingOnPoint(snake.getHeadPoint())
                && board.getBoardObjectByPoint(snake.getHeadPoint()).getType() == BoardObject::Food) {
            board.removeBoardObjectOnPoint(snake.getHeadPoint());
            snake.grow();
            food = Food(static_cast<Point::PointPosition>(rand()) % board.getX(),
                        static_cast<Point::PointPosition>(rand()) % board.getY());
        }

        usleep(10000);
    }

    return 0;
}

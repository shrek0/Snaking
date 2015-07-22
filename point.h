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

#ifndef POINT_H
#define POINT_H

#include <cstdint>
#include <unordered_map>

#include <cstdint>

class Point
{
public:
    typedef std::size_t PointPosition;
    Point(PointPosition x, PointPosition y);
    Point() { }

    bool operator == (const Point &point) const
    {
        return x == point.x && y == point.y;
    }

    bool operator < (const Point &point) const
    {
        return x < point.x && y < point.y;
    }

    Point operator + (const Point &point) const
    {
        return Point(x+point.x, y+point.y);
    }

    Point &operator += (const Point &point) {
        x = point.x;
        y = point.y;
        return *this;
    }

    PointPosition x;
    PointPosition y;
};

//namespace std
//{
//template<>
//struct std::hash<Point> :
//    public __hash_base<size_t, Point>
//{

//};
//}

namespace std {

//bool operator == (const Point &first, const Point &second)
//{
//    return first.x == second.x && first.y == second.y;
//}

template <>
struct hash<Point>
{
    std::size_t operator()(const Point &point) const
    {
        using std::size_t;
        using std::hash;

        return hash<uint64_t>()(point.x + point.y);
    }
};

}

#endif // POINT_H

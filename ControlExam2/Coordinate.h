#pragma once

#ifndef __COORDINATE_STRUCT__
#define __COORDINATE_STRUCT__

struct Coordinate
{
    Coordinate(const int x, const int y)
    : x(x),
      y(y)
    {}

    int x, y;
};

#endif // __COORDINATE_STRUCT__ 
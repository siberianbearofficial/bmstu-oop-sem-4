#ifndef POINT_H
#define POINT_H

#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "action.h"
#include "my_error.h"

typedef struct point
{
    double x;
    double y;
    double z;
} point_t;

my_error_t point_initialize(point_t &point);

my_error_t point_read(FILE *fin, point_t &point);

my_error_t point_write(FILE *fout, const point_t &point);

my_error_t point_move(point_t &point, const move_t &vector);

my_error_t point_rotate(point_t &point, const point_t &center, const rotate_t &angles);

my_error_t point_scale(point_t &point, const point_t &center, const scale_t &coefficients);

#endif // POINT_H

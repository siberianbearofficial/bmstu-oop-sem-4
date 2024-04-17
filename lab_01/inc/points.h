#ifndef POINTS_H
#define POINTS_H

#include <cstdio>
#include <cstdlib>

#include "point.h"
#include "my_error.h"

typedef struct points
{
    point_t *array;
    int size;
} points_t;

my_error_t points_allocate(points_t **points);

my_error_t points_free(points_t **points);

my_error_t points_initialize(points_t &points);

my_error_t points_read(points_t &points, FILE *fin);

my_error_t points_write(const points_t &points, FILE *fout);

my_error_t points_move(points_t &points, const move_t &vector);

my_error_t points_rotate(points_t &points, const point_t &center, const rotate_t &angles);

my_error_t points_scale(points_t &points, const point_t &center, const scale_t &coefficients);

my_error_t points_get(const points_t &points, point_t **point, const int index);

#endif // POINTS_H

#ifndef FIGURE_H
#define FIGURE_H

#include <cstdio>

#include "points.h"
#include "edges.h"
#include "action.h"
#include "my_error.h"

typedef struct figure
{
    point_t center;
    points_t *points;
    edges_t *edges;
} figure_t;

my_error_t figure_free(figure_t **figure);

my_error_t figure_load(figure_t **figure, const char *filename);

my_error_t figure_save(figure_t *figure, const char *filename);

my_error_t figure_move(figure_t *figure, const move_t &vector);

my_error_t figure_rotate(figure_t *figure, const rotate_t &angles);

my_error_t figure_scale(figure_t *figure, const scale_t &coefficient);

#endif // FIGURE_H

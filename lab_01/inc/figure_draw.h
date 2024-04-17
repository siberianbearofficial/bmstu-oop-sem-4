#ifndef DRAW_FIGURE_H
#define DRAW_FIGURE_H

#include <QGraphicsScene>

#include "figure.h"
#include "points.h"

typedef struct view
{
    QGraphicsScene *scene;
    double width;
    double height;
} view_t;

typedef struct line
{
    point_t p1;
    point_t p2;
} segment_t;

my_error_t figure_draw(figure_t *figure, const view_t &view);

#endif // DRAW_FIGURE_H

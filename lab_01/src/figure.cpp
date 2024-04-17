#include "figure.h"

static my_error_t figure_center_reset(point_t &center, points_t &points)
{
    point_t *point;
    my_error_t rc = points_get(points, &point, 0);
    if (rc != SUCCESS)
        return rc;

    double min_x = point->x, max_x = point->x;
    double min_y = point->y, max_y = point->z;
    double min_z = point->z, max_z = point->y;

    for (int i = 1; rc == SUCCESS && i < points.size; i++)
    {
        rc = points_get(points, &point, i);
        if (rc == SUCCESS)
        {
            if (point->x < min_x)
                min_x = point->x;
            if (point->x > max_x)
                max_x = point->x;
            if (point->y < min_y)
                min_y = point->y;
            if (point->y > max_y)
                max_y = point->y;
            if (point->z < min_z)
                min_z = point->z;
            if (point->z > max_z)
                max_z = point->z;
        }
    }

    if (rc == SUCCESS)
    {
        center.x = (max_x + min_x) / 2;
        center.y = (max_y + min_y) / 2;
        center.z = (max_z + min_z) / 2;
    }

    return rc;
}

my_error_t figure_free(figure_t **figure)
{
    if (!figure)
        return NULLPTR_ERROR;

    my_error_t rc = points_free(&(*figure)->points);
    if (rc != SUCCESS)
        return rc;

    rc = edges_free(&(*figure)->edges);
    if (rc != SUCCESS)
        return rc;

    free(*figure);
    *figure = nullptr;

    return rc;
}

static my_error_t figure_read(figure_t **figure, FILE *fin)
{
    if (!fin || !figure)
        return NULLPTR_ERROR;

    auto *tmp_figure = (figure_t *) malloc(sizeof(figure_t));
    if (!tmp_figure)
        return MEMORY_ERROR;

    my_error_t rc = points_read(&tmp_figure->points, fin);
    if (rc != SUCCESS)
    {
        free(tmp_figure);
        return rc;
    }

    rc = edges_read(&tmp_figure->edges, fin);
    if (rc != SUCCESS)
    {
        free(tmp_figure);
        return rc;
    }

    *figure = tmp_figure;

    return rc;
}

my_error_t figure_load(figure_t **figure, const char *filename)
{
    if (!figure)
        return NULLPTR_ERROR;
    if (!filename)
        return FILE_OPEN_ERROR;

    FILE *fin = fopen(filename, "r");
    if (!fin)
        return FILE_OPEN_ERROR;

    my_error_t rc = figure_read(figure, fin);
    if (rc == SUCCESS)
        rc = figure_center_reset((*figure)->center, *(*figure)->points);
    else
        figure_free(figure);

    fclose(fin);

    return rc;
}

static my_error_t figure_write(const figure_t &figure, FILE *fout)
{
    my_error_t rc;
    if (!fout)
        return NULLPTR_ERROR;

    rc = points_write(*figure.points, fout);
    if (rc == SUCCESS)
        rc = edges_write(*figure.edges, fout);

    return rc;
}

my_error_t figure_save(figure_t *figure, const char *filename)
{
    if (!filename)
        return FILE_OPEN_ERROR;
    if (!figure)
        return NULLPTR_ERROR;

    FILE *fout = fopen(filename, "w");
    if (!fout)
        return FILE_WRITE_ERROR;

    my_error_t rc = figure_write(*figure, fout);

    fclose(fout);

    return rc;
}


my_error_t figure_move(figure_t *figure, const move_t &vector)
{
    if (!figure)
        return NULLPTR_ERROR;

    my_error_t rc = point_move(figure->center, vector);
    if (rc != SUCCESS)
        return rc;

    rc = points_move(*figure->points, vector);

    return rc;
}

my_error_t figure_scale(figure_t *figure, const scale_t &coefficients)
{
    if (!figure)
        return NULLPTR_ERROR;
    return points_scale(*figure->points, figure->center, coefficients);
}

my_error_t figure_rotate(figure_t *figure, const rotate_t &angles)
{
    if (!figure)
        return NULLPTR_ERROR;
    return points_rotate(*figure->points, figure->center, angles);
}

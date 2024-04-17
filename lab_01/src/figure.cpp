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


my_error_t figure_allocate(figure_t **figure)
{
    my_error_t rc;
    if (!figure)
        return NULLPTR_ERROR;

    auto *tmp_figure = (figure_t *) malloc(sizeof(figure_t));
    if (!tmp_figure)
        return MEMORY_ERROR;

    *figure = tmp_figure;
    rc = points_allocate(&(*figure)->points);
    if (rc == SUCCESS)
        rc = edges_allocate(&(*figure)->edges);

    return rc;
}

my_error_t figure_free(figure_t **figure)
{
    my_error_t rc;
    if (!figure)
        return NULLPTR_ERROR;

    rc = points_free(&(*figure)->points);
    if (rc != SUCCESS)
        return rc;

    rc = edges_free(&(*figure)->edges);
    if (rc == SUCCESS)
        free(*figure);

    return rc;
}

my_error_t figure_initialize(figure_t &figure) {
    my_error_t rc = point_initialize(figure.center);
    if (rc != SUCCESS)
        return rc;

    rc = points_initialize(*figure.points);
    if (rc == SUCCESS)
        rc = edges_initialize(*figure.edges);

    return rc;
}

my_error_t figure_create(figure_t **figure)
{
    my_error_t rc = figure_allocate(figure);
    if (rc != SUCCESS)
        return rc;

    rc = figure_initialize(**figure);

    return rc;
}

static my_error_t figure_read_content(figure_t &figure, FILE *fin)
{
    my_error_t rc = points_read(*figure.points, fin);
    if (rc != SUCCESS)
        return rc;

    rc = edges_read(*figure.edges, fin);
    if (rc != SUCCESS)
        points_free(&figure.points);

    return rc;
}


static my_error_t figure_read(figure_t **figure, FILE *fin)
{
    if (!fin || !figure)
        return NULLPTR_ERROR;

    figure_t *new_figure;

    // todo какая-то херня тут происходит, слишком много действий. надо выпилить allocate памяти и спрятать ее в read
    my_error_t rc = figure_allocate(&new_figure);
    if (rc != SUCCESS)
        return rc;

    rc = figure_initialize(*new_figure);
    if (rc != SUCCESS)
    {
        figure_free(&new_figure);
        return rc;
    }

    rc = figure_read_content(*new_figure, fin);
    if (rc != SUCCESS)
    {
        figure_free(&new_figure);
        return rc;
    }

    *figure = new_figure;

    return rc;
}

my_error_t figure_load(figure_t **figure, const char *filename)
{
    if (!filename)
        return FILE_OPEN_ERROR;

    FILE *fin = fopen(filename, "r");
    if (!fin)
        return FILE_OPEN_ERROR;

    my_error_t rc = figure_read(figure, fin);
    if (rc == SUCCESS)
        rc = figure_center_reset((*figure)->center, *(*figure)->points);

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

my_error_t figure_save(const figure_t &figure, const char *filename)
{
    if (!filename)
        return FILE_OPEN_ERROR;

    FILE *fout = fopen(filename, "w");
    if (!fout)
        return FILE_WRITE_ERROR;

    my_error_t rc = figure_write(figure, fout);

    fclose(fout);

    return rc;
}


my_error_t figure_move(figure_t &figure, const move_t &vector)
{
    my_error_t rc = point_move(figure.center, vector);
    if (rc != SUCCESS)
        return rc;

    rc = points_move(*figure.points, vector);

    return rc;
}

my_error_t figure_scale(figure_t &figure, const scale_t &coefficients)
{
    return points_scale(*figure.points, figure.center, coefficients);
}

my_error_t figure_rotate(figure_t &figure, const rotate_t &angles)
{
    return points_rotate(*figure.points, figure.center, angles);
}

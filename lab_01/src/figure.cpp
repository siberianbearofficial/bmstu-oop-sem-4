#include "figure.h"

static my_error_t figure_center_reset(point_t &center, points_t &points)
{
    point_t *point;
    my_error_t rc = points_get(points, &point, 0);
    if (rc == SUCCESS)
    {
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
            center.x = (max_x - min_x) / 2;
            center.y = (max_y - min_y) / 2;
            center.z = (max_z - min_z) / 2;
        }
    }
    return rc;
}


my_error_t figure_allocate(figure_t **figure)
{
    my_error_t rc;
    if (figure)
    {
        auto *tmp_figure = (figure_t *) malloc(sizeof(figure_t));
        if (tmp_figure)
        {
            *figure = tmp_figure;
            rc = points_allocate(&(*figure)->points);
            if (rc == SUCCESS)
                rc = edges_allocate(&(*figure)->edges);
        }
        else
            rc = MEMORY_ERROR;
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}

my_error_t figure_free(figure_t **figure)
{
    my_error_t rc;
    if (figure)
    {
        rc = points_free(&(*figure)->points);
        if (rc == SUCCESS)
        {
            rc = edges_free(&(*figure)->edges);
            if (rc == SUCCESS)
                free(*figure);
        }
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}

my_error_t figure_initialize(figure_t &figure) {
    my_error_t rc = point_initialize(figure.center);
    if (rc == SUCCESS)
    {
        rc = points_initialize(*figure.points);
        if (rc == SUCCESS)
            rc = edges_initialize(*figure.edges);
    }
    return rc;
}

my_error_t figure_create(figure_t **figure)
{
    my_error_t rc = figure_allocate(figure);
    if (rc == SUCCESS)
        rc = figure_initialize(**figure);
    return rc;
}


static my_error_t figure_read(FILE *fin, figure_t &figure)
{
    my_error_t rc;
    if (fin)
    {
        rc = points_read(fin, *figure.points);
        if (rc == SUCCESS)
        {
            rc = edges_read(fin, *figure.edges);
            if (rc != SUCCESS)
                points_free(&figure.points);
        }
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}

my_error_t figure_load(figure_t **figure, const char *filename)
{
    my_error_t rc;
    if (filename)
    {
        FILE *fin = fopen(filename, "r");
        if (fin)
        {
            figure_t *new_figure;
            rc = figure_allocate(&new_figure);
            if (rc == SUCCESS)
            {
                rc = figure_initialize(*new_figure);
                if (rc == SUCCESS)
                {
                    rc = figure_read(fin, *new_figure);
                    if (rc == SUCCESS)
                    {
                        rc = figure_free(figure);
                        if (rc == SUCCESS)
                        {
                            *figure = new_figure;
                            rc = figure_center_reset((*figure)->center, *(*figure)->points);
                        }
                        else
                            figure_free(&new_figure);
                    }
                    else
                        figure_free(&new_figure);
                }
                else
                    figure_free(&new_figure);
            }
            fclose(fin);
        }
        else
            rc = FILE_OPEN_ERROR;
    }
    else
        rc = FILE_OPEN_ERROR;
    return rc;
}


static my_error_t figure_write(FILE *fout, const figure_t &figure)
{
    my_error_t rc;
    if (fout)
    {
        rc = points_write(fout, *figure.points);
        if (rc == SUCCESS)
            rc = edges_write(fout, *figure.edges);
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}

my_error_t figure_save(const figure_t &figure, const char *filename)
{
    my_error_t rc;
    if (filename)
    {
        FILE *fout = fopen(filename, "w");
        if (fout)
        {
            rc = figure_write(fout, figure);
            fclose(fout);
        }
        else
            rc = FILE_WRITE_ERROR;
    }
    else
        rc = FILE_OPEN_ERROR;
    return rc;
}


my_error_t figure_move(figure_t &figure, const move_t &vector)
{
    my_error_t rc = point_move(figure.center, vector);
    if (rc == SUCCESS)
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

#include "points.h"

static my_error_t points_array_allocate(point_t **array, const int size)
{
    my_error_t rc = SUCCESS;
    if (!array)
        rc = NULLPTR_ERROR;
    else if (size < 0)
        rc = POINTS_SIZE_ERROR;
    else
    {
        auto *tmp_array = (point_t *) malloc(size * sizeof(point_t));
        if (tmp_array)
            *array = tmp_array;
        else
            rc = MEMORY_ERROR;
    }
    return rc;
}

my_error_t points_allocate(points_t **points) {
    my_error_t rc = SUCCESS;
    if (points) {
        auto *tmp_points = (points_t *) malloc(sizeof(points_t));
        if (tmp_points)
            *points = tmp_points;
        else
            rc = MEMORY_ERROR;
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}

static my_error_t points_array_free(point_t **array) {
    my_error_t rc = SUCCESS;
    if (!array)
        rc = NULLPTR_ERROR;
    else if (*array)
        free(*array);
    return rc;
}

my_error_t points_free(points_t **points) {
    my_error_t rc;
    if (points) {
        rc = points_array_free(&(*points)->array);
        if (rc == SUCCESS)
            free(*points);
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}

my_error_t points_initialize(points_t &points) {
    points.array = nullptr;
    points.size = 0;
    return SUCCESS;
}


static my_error_t points_size_read(FILE *fin, int &size)
{
    my_error_t rc = SUCCESS;
    if (fin == nullptr)
        rc = NULLPTR_ERROR;
    else if (fscanf(fin, "%d", &size) != 1)
        rc = FILE_READ_ERROR;
    else if (size <= 0)
        rc = POINTS_SIZE_ERROR;
    return rc;
}

static my_error_t points_array_read(FILE *fin, point_t *array, const int size)
{
    my_error_t rc = SUCCESS;
    if (fin == nullptr)
        rc = NULLPTR_ERROR;
    else if (array == nullptr)
        rc = NO_DATA_ERROR;
    else if (size <= 0)
        rc = POINTS_SIZE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < size; i++)
            rc = point_read(fin, array[i]);
    return rc;
}

my_error_t points_read(FILE *fin, points_t &points)
{
    my_error_t rc;
    if (fin) {
        rc = points_size_read(fin, points.size);
        if (rc == SUCCESS)
        {
            rc = points_array_allocate(&points.array, points.size);
            if (rc == SUCCESS)
            {
                rc = points_array_read(fin, points.array, points.size);
                if (rc != SUCCESS)
                    points_array_free(&points.array);
            }
        }
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}


static my_error_t points_size_write(FILE *fout, const int size) {
    my_error_t rc = SUCCESS;
    if (fout == nullptr)
        rc = NULLPTR_ERROR;
    else if (size < 0)
        rc = POINTS_SIZE_ERROR;
    else if (0 > fprintf(fout, "%d\n", size))
        rc = FILE_WRITE_ERROR;
    return rc;
}

static my_error_t points_array_write(FILE *fout, const point_t *array, const int size) {
    my_error_t rc = SUCCESS;
    if (fout == nullptr)
        rc = NULLPTR_ERROR;
    else if (array == nullptr)
        rc = NO_DATA_ERROR;
    else if (size < 0)
        rc = POINTS_SIZE_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < size; i++)
            rc = point_write(fout, array[i]);
    return rc;
}

my_error_t points_write(FILE *fout, const points_t &points)
{
    my_error_t rc;
    if (fout)
    {
        rc = points_size_write(fout, points.size);
        if (rc == SUCCESS)
            rc = points_array_write(fout, points.array, points.size);
    }
    else
        rc = NULLPTR_ERROR;
    return rc;
}


my_error_t points_move(points_t &points, const move_t &vector)
{
    my_error_t rc = SUCCESS;
    if (points.array == nullptr)
        rc = FIGURE_LOAD_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = point_move(points.array[i], vector);
    return rc;
}

my_error_t points_rotate(points_t &points, const point_t &center, const rotate_t &angles)
{
    my_error_t rc = SUCCESS;
    if (points.array == nullptr)
        rc = FIGURE_LOAD_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = point_rotate(points.array[i], center, angles);
    return rc;
}

my_error_t points_scale(points_t &points, const point_t &center, const scale_t &coefficients)
{
    my_error_t rc = SUCCESS;
    if (points.array == nullptr)
        rc = FIGURE_LOAD_ERROR;
    else if (coefficients.kx == 0 || coefficients.ky == 0 || coefficients.kz == 0)
        rc = SCALE_COEFFICIENT_ERROR;
    else
        for (int i = 0; rc == SUCCESS && i < points.size; i++)
            rc = point_scale(points.array[i], center, coefficients);
    return rc;
}


my_error_t points_get(const points_t &points, point_t **point, const int index)
{
    my_error_t rc = SUCCESS;
    if (points.array && points.size > 0)
        *point = &points.array[index];
    else
        rc = NO_DATA_ERROR;
    return rc;
}

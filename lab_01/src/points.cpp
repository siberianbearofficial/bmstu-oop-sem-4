#include "points.h"

static my_error_t points_array_allocate(point_t **array, const int size)
{
    if (!array)
        return NULLPTR_ERROR;

    if (size < 0)
        return POINTS_SIZE_ERROR;

    auto *tmp_array = (point_t *) malloc(size * sizeof(point_t));
    if (!tmp_array)
        return MEMORY_ERROR;

    *array = tmp_array;

    return SUCCESS;
}

my_error_t points_allocate(points_t **points) {
    if (!points)
        return NULLPTR_ERROR;

    auto *tmp_points = (points_t *) malloc(sizeof(points_t));
    if (!tmp_points)
        return MEMORY_ERROR;

    *points = tmp_points;

    return SUCCESS;
}

static my_error_t points_array_free(point_t **array) {
    if (!array)
        return NULLPTR_ERROR;

    if (*array)
        free(*array);

    return SUCCESS;
}

my_error_t points_free(points_t **points) {
    if (!points)
        return NULLPTR_ERROR;

    my_error_t rc = points_array_free(&(*points)->array);
    if (rc == SUCCESS)
        free(*points);

    return rc;
}

my_error_t points_initialize(points_t &points) {
    points.array = nullptr;
    points.size = 0;
    return SUCCESS;
}


static my_error_t points_size_read(int &size, FILE *fin)
{
    if (!fin)
        return NULLPTR_ERROR;

    if (fscanf(fin, "%d", &size) != 1)
        return FILE_READ_ERROR;

    if (size <= 0)
        return POINTS_SIZE_ERROR;

    return SUCCESS;
}

static my_error_t points_array_read(point_t *array, const int size, FILE *fin)
{
    if (!fin)
        return NULLPTR_ERROR;

    if (!array)
        return NO_DATA_ERROR;

    if (size <= 0)
        return POINTS_SIZE_ERROR;

    my_error_t rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i < size; i++)
        rc = point_read(array[i], fin);

    return rc;
}

my_error_t points_read(points_t &points, FILE *fin)
{
    if (!fin)
        return NULLPTR_ERROR;

    my_error_t rc = points_size_read(points.size, fin);
    if (rc != SUCCESS)
        return rc;

    rc = points_array_allocate(&points.array, points.size);
    if (rc != SUCCESS)
        return rc;

    rc = points_array_read(points.array, points.size, fin);
    if (rc != SUCCESS)
        points_array_free(&points.array);

    return rc;
}


static my_error_t points_size_write(const int size, FILE *fout) {
    if (!fout)
        return NULLPTR_ERROR;

    if (size < 0)
        return POINTS_SIZE_ERROR;

    if (0 > fprintf(fout, "%d\n", size))
        return FILE_WRITE_ERROR;

    return SUCCESS;
}

static my_error_t points_array_write(const point_t *array, const int size, FILE *fout) {
    if (!fout)
        return NULLPTR_ERROR;

    if (!array)
        return NO_DATA_ERROR;

    if (size < 0)
        return POINTS_SIZE_ERROR;

    my_error_t rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i < size; i++)
        rc = point_write(array[i], fout);

    return rc;
}

my_error_t points_write(const points_t &points, FILE *fout)
{
    if (!fout)
        return NULLPTR_ERROR;

    my_error_t rc = points_size_write(points.size, fout);
    if (rc == SUCCESS)
        rc = points_array_write(points.array, points.size, fout);

    return rc;
}


my_error_t points_move(points_t &points, const move_t &vector)
{
    if (!points.array)
        return FIGURE_LOAD_ERROR;

    my_error_t rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i < points.size; i++)
        rc = point_move(points.array[i], vector);

    return rc;
}

my_error_t points_rotate(points_t &points, const point_t &center, const rotate_t &angles)
{
    if (!points.array)
        return FIGURE_LOAD_ERROR;

    my_error_t rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i < points.size; i++)
        rc = point_rotate(points.array[i], center, angles);

    return rc;
}

my_error_t points_scale(points_t &points, const point_t &center, const scale_t &coefficients)
{
    if (!points.array)
        return FIGURE_LOAD_ERROR;

    if (coefficients.kx == 0 || coefficients.ky == 0 || coefficients.kz == 0)
        return SCALE_COEFFICIENT_ERROR;

    my_error_t rc = SUCCESS;
    for (int i = 0; rc == SUCCESS && i < points.size; i++)
        rc = point_scale(points.array[i], center, coefficients);

    return rc;
}


my_error_t points_get(const points_t &points, point_t **point, const int index)
{
    if (!points.array || points.size <= 0)
        return NO_DATA_ERROR;

    *point = &points.array[index];

    return SUCCESS;
}

#include "point.h"

my_error_t point_initialize(point_t &point)
{
    point.x = 0.0;
    point.y = 0.0;
    point.z = 0.0;
    return SUCCESS;
}


my_error_t point_read(FILE *fin, point_t &point)
{
    my_error_t rc = SUCCESS;
    if (fin == nullptr)
        rc = FILE_OPEN_ERROR;
    else if (fscanf(fin, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        rc = FILE_READ_ERROR;
    return rc;
}

my_error_t point_write(FILE *fout, const point_t &point)
{
    my_error_t rc = SUCCESS;
    if (0 > fprintf(fout, "%lf %lf %lf\n", point.x, point.y, point.z))
        rc = FILE_WRITE_ERROR;
    return rc;
}


my_error_t point_move(point_t &point, const move_t &vector)
{
    point.x += vector.dx;
    point.y += vector.dy;
    point.z += vector.dz;
    return SUCCESS;
}

my_error_t point_scale(point_t &point, const point_t &center, const scale_t &coefficients)
{
    point.x = (point.x - center.x) * coefficients.kx + center.x;
    point.y = (point.y - center.y) * coefficients.ky + center.y;
    point.z = (point.z - center.z) * coefficients.kz + center.z;
    return SUCCESS;
}


static inline double degrees_to_radians(const double &angle) {
    return angle * (M_PI / 180);
}

static my_error_t point_rotate_x(point_t &point, const point_t &center, const double angle)
{
    double angle_cos = cos(degrees_to_radians(angle));
    double angle_sin = sin(degrees_to_radians(angle));
    double y = point.y;

    point.y = (point.y - center.y)  * angle_cos + (point.z - center.z) * angle_sin + center.y;
    point.z = -(y - center.y) * angle_sin + (point.z - center.z) * angle_cos + center.z;
    return SUCCESS;
}

static my_error_t point_rotate_y(point_t &point, const point_t &center, const double angle)
{
    double angle_cos = cos(degrees_to_radians(angle));
    double angle_sin = sin(degrees_to_radians(angle));
    double x = point.x;

    point.x = (point.x - center.x) * angle_cos + (point.z - center.z) * angle_sin + center.x;
    point.z = -(x - center.x) * angle_sin + (point.z - center.z) * angle_cos + center.z;
    return SUCCESS;
}

static my_error_t point_rotate_z(point_t &point, const point_t &center, const double angle)
{
    double angle_cos = cos(degrees_to_radians(angle));
    double angle_sin = sin(degrees_to_radians(angle));
    double x = point.x;

    point.x = (point.x - center.x) * angle_cos + (point.y - center.y) * angle_sin + center.x;
    point.y = -(x - center.x) * angle_sin + (point.y - center.y) * angle_cos + center.y;
    return SUCCESS;
}

my_error_t point_rotate(point_t &point, const point_t &center, const rotate_t &angles)
{
    point_rotate_x(point, center, angles.ax);
    point_rotate_y(point, center, angles.ay);
    point_rotate_z(point, center, angles.az);
    return SUCCESS;
}

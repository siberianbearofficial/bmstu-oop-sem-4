#ifndef ACTION_H
#define ACTION_H

typedef struct move
{
    double dx;
    double dy;
    double dz;
} move_t;

typedef struct rotate
{
    double ax;
    double ay;
    double az;
} rotate_t;

typedef struct scale
{
    double kx;
    double ky;
    double kz;
} scale_t;

typedef enum action
{
    INIT,
    SAVE,
    LOAD,
    ROTATE,
    MOVE,
    SCALE,
    DRAW,
    QUIT
} action_t;

#endif // ACTION_H

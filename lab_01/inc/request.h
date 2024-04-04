#ifndef REQUESTS_H
#define REQUESTS_H

#include "figure.h"
#include "figure_draw.h"
#include "action.h"
#include "my_error.h"

typedef struct request
{
    action_t action;
    union
    {
        const char *filename;
        view_t view;
        rotate_t angles;
        move_t vector;
        scale_t coefficients;
    };
} request_t;

my_error_t request_process(request_t &request);

#endif // REQUESTS_H

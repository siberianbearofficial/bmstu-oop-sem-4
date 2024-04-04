#include "request.h"

my_error_t request_process(request_t &request)
{
    static figure_t *figure;
    my_error_t rc;
    switch (request.action)
    {
        case INIT:
            rc = figure_create(&figure);
            break;
        case SAVE:
            rc = figure_save(*figure, request.filename);
            break;
        case LOAD:
            rc = figure_load(&figure, request.filename);
            break;
        case MOVE:
            rc = figure_move(*figure, request.vector);
            break;
        case SCALE:
            rc = figure_scale(*figure, request.coefficients);
            break;
        case ROTATE:
            rc = figure_rotate(*figure, request.angles);
            break;
        case DRAW:
            rc = figure_draw(*figure, request.view);
            break;
        case QUIT:
            rc = figure_free(&figure);
            break;
        default:
            rc = NO_COMMAND_ERROR;
    }
    return rc;
}

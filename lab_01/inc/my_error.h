#ifndef MY_ERROR_H
#define MY_ERROR_H

#include <QMessageBox>

typedef enum my_error
{
    SUCCESS,
    FILE_OPEN_ERROR,
    FILE_READ_ERROR,
    FILE_WRITE_ERROR,
    FILE_CLOSE_ERROR,
    FIGURE_LOAD_ERROR,
    POINTS_SIZE_ERROR,
    EDGES_SIZE_ERROR,
    SCENE_ERROR,
    MEMORY_ERROR,
    SCALE_COEFFICIENT_ERROR,
    NO_DATA_ERROR,
    NO_COMMAND_ERROR,
    NULLPTR_ERROR
} my_error_t;

void my_error_show(my_error_t &error);

#endif // MY_ERROR_H

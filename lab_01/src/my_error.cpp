#include "my_error.h"

void my_error_show(my_error_t &error)
{
    switch (error)
    {
        case FILE_OPEN_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "Не удалось открыть файл.");
            break;
        case FILE_CLOSE_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "Не удалось закрыть файл.");
            break;
        case FILE_READ_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "Не удалось прочитать файл.");
            break;
        case FILE_WRITE_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "Некорректные данные при записи файла.");
            break;
        case MEMORY_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "Не удалось выделить память.");
            break;
        case POINTS_SIZE_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "Количество точек в файле должно быть больше 0.");
            break;
        case EDGES_SIZE_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "Количество ребер в файле должно быть больше 0.");
            break;
        case SCENE_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "При попытке нарисовать фигуру произошла ошибка.");
            break;
        case SCALE_COEFFICIENT_ERROR:
            QMessageBox::critical(nullptr, "Ошибка!", "Коэффициенты масштабирования не должны равняться 0.");
            break;
        case NO_DATA_ERROR:
            QMessageBox::information(nullptr, "Информация!", "Нет данных фигуры для записи.");
            break;
        case FIGURE_LOAD_ERROR:
            QMessageBox::information(nullptr, "Информация!", "Фигура не загружена.");
            break;
        default:
            QMessageBox::critical(nullptr, "Ошибка!", "Что-то пошло не по плану...");
    };
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "request.h"
#include "my_error.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    void on_actionLoad_clicked();

    void on_actionSave_clicked();

    static void on_actionInfFile_clicked();

    static void on_actionInfProgram_clicked();

    static void on_actionInfDeveloper_clicked();

private slots:
    my_error_t draw();

    void on_buttonMoving_clicked();

    void on_buttonTurn_clicked();

    void on_buttonScale_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

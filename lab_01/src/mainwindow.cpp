#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    connect(ui->actionLoad, &QAction::triggered, this,
            &MainWindow::on_actionLoad_clicked);

    connect(ui->actionSave, &QAction::triggered, this,
            &MainWindow::on_actionSave_clicked);

    connect(ui->actionInfFile, &QAction::triggered, this,
            &MainWindow::on_actionInfFile_clicked);

    connect(ui->actionInfProgram, &QAction::triggered, this,
            &MainWindow::on_actionInfProgram_clicked);

    connect(ui->actionInfDeveloper, &QAction::triggered, this,
            &MainWindow::on_actionInfDeveloper_clicked);
}

MainWindow::~MainWindow()
{
    request_t request;
    request.action = QUIT;
    request_process(request);
    delete ui;
}

my_error_t MainWindow::draw()
{
    auto graphics_view_content = ui->graphicsView->contentsRect();
    ui->graphicsView->scene()->setSceneRect(0, 0,
                                            graphics_view_content.width(),
                                            graphics_view_content.height());

    request_t request;
    request.action = DRAW;
    request.view = {
        .scene = ui->graphicsView->scene(),
        .width =  ui->graphicsView->scene()->width(),
        .height =  ui->graphicsView->scene()->height()
    };

    return request_process(request);
}

void MainWindow::on_actionSave_clicked()
{
    QString path = QFileDialog::getSaveFileName();

    request_t request;
    request.action = SAVE;
    request.filename = path.toUtf8().data();

    my_error_t rc = request_process(request);
    if (rc != SUCCESS)
    {
        my_error_show(rc);
        return;
    }

    rc = draw();
    if (rc != SUCCESS)
        my_error_show(rc);
}

void MainWindow::on_actionLoad_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    request_t request;
    request.action = LOAD;
    request.filename = path.toUtf8().data();

    my_error_t rc = request_process(request);
    if (rc != SUCCESS)
    {
        my_error_show(rc);
        return;
    }

    rc = draw();
    if (rc != SUCCESS)
        my_error_show(rc);
}

void MainWindow::on_actionInfFile_clicked()
{
    QMessageBox::information(nullptr, "Информация о входном файле",
                             "В начале файла необходимо указывать количество точек.\n"
                             "Далее должны идти точки в формате: x y z.\n"
                             "После указывается количество ребер.\n"
                             "Затем идут ребра в формате: точка_1 точка_2,\n"
                             "где точка_i - номер точки в файле (нумерация с нуля).\n"
                             "Такое ребро соединяет точку 1 с точкой 2.\n"
                             "Ребра и точки могут задаваться в произвольном порядке.\n");
}

void MainWindow::on_actionInfProgram_clicked()
{
    QMessageBox::information(nullptr, "Информация о программе",
                             "3D Viewer - программа для для просмотра"
                             "каркасных 3D моделей с возможностью их"
                             "перемещения, масштабирования и вращения.");
}

void MainWindow::on_actionInfDeveloper_clicked()
{
    QMessageBox::information(nullptr, "Информация о разработчике", "Автор: Орлов Алексей (Группа: ИУ7-44Б)");
}

void MainWindow::on_buttonMoving_clicked()
{
    request_t request;
    request.action = MOVE;
    request.vector = {
        .dx = ui->enterXMoving->value(),
        .dy = ui->enterYMoving->value(),
        .dz = ui->enterZMoving->value()
    };

    my_error_t rc = request_process(request);
    if (rc != SUCCESS)
    {
        my_error_show(rc);
        return;
    }

    rc = draw();
    if (rc != SUCCESS)
        my_error_show(rc);
}

void MainWindow::on_buttonTurn_clicked()
{
    request_t request;
    request.action = ROTATE;
    request.angles = {
        .ax = ui->enterXTurn->value(),
        .ay = ui->enterYTurn->value(),
        .az = ui->enterZTurn->value()
    };

    my_error_t rc = request_process(request);
    if (rc != SUCCESS)
    {
        my_error_show(rc);
        return;
    }

    rc = draw();
    if (rc != SUCCESS)
        my_error_show(rc);
}

void MainWindow::on_buttonScale_clicked()
{
    request_t request;
    request.action = SCALE;
    request.coefficients = {
        .kx = ui->enterXScale->value(),
        .ky = ui->enterYScale->value(),
        .kz = ui->enterZScale->value()
    };

    my_error_t rc = request_process(request);
    if (rc != SUCCESS)
    {
        my_error_show(rc);
        return;
    }

    rc = draw();
    if (rc != SUCCESS)
        my_error_show(rc);

}

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionInfFile;
    QAction *actionInfProgram;
    QAction *actionInfDeveloper;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupMoving;
    QGridLayout *gridGroupMoving;
    QDoubleSpinBox *enterZMoving;
    QLabel *labelYMoving;
    QLabel *labelZMoving;
    QLabel *labelXMoving;
    QPushButton *buttonMoving;
    QDoubleSpinBox *enterXMoving;
    QDoubleSpinBox *enterYMoving;
    QGroupBox *groupTurn;
    QGridLayout *gridGroupTurn;
    QLabel *labelZTurn;
    QLabel *labelYTurn;
    QDoubleSpinBox *enterZTurn;
    QLabel *labelXTurn;
    QDoubleSpinBox *enterYTurn;
    QDoubleSpinBox *enterXTurn;
    QPushButton *buttonTurn;
    QGroupBox *groupScale;
    QGridLayout *gridGroupScale;
    QLabel *labelZScale;
    QDoubleSpinBox *enterZScale;
    QDoubleSpinBox *enterYScale;
    QLabel *labelYScale;
    QLabel *labelXScale;
    QDoubleSpinBox *enterXScale;
    QPushButton *buttonScale;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *actionsFile;
    QMenu *actionsInformation;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1011, 672);
        MainWindow->setMinimumSize(QSize(1000, 672));
        MainWindow->setToolTipDuration(-6);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionInfFile = new QAction(MainWindow);
        actionInfFile->setObjectName(QString::fromUtf8("actionInfFile"));
        actionInfProgram = new QAction(MainWindow);
        actionInfProgram->setObjectName(QString::fromUtf8("actionInfProgram"));
        actionInfDeveloper = new QAction(MainWindow);
        actionInfDeveloper->setObjectName(QString::fromUtf8("actionInfDeveloper"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setToolTipDuration(-1);
        centralwidget->setInputMethodHints(Qt::ImhNone);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(50);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupMoving = new QGroupBox(centralwidget);
        groupMoving->setObjectName(QString::fromUtf8("groupMoving"));
        groupMoving->setMinimumSize(QSize(249, 173));
        groupMoving->setMaximumSize(QSize(16777215, 173));
        QFont font;
        font.setPointSize(12);
        groupMoving->setFont(font);
        gridGroupMoving = new QGridLayout(groupMoving);
        gridGroupMoving->setObjectName(QString::fromUtf8("gridGroupMoving"));
        gridGroupMoving->setHorizontalSpacing(15);
        gridGroupMoving->setVerticalSpacing(20);
        gridGroupMoving->setContentsMargins(10, 10, 10, 10);
        enterZMoving = new QDoubleSpinBox(groupMoving);
        enterZMoving->setObjectName(QString::fromUtf8("enterZMoving"));
        enterZMoving->setMinimum(-1000.000000000000000);
        enterZMoving->setMaximum(1000.000000000000000);

        gridGroupMoving->addWidget(enterZMoving, 1, 2, 1, 1);

        labelYMoving = new QLabel(groupMoving);
        labelYMoving->setObjectName(QString::fromUtf8("labelYMoving"));
        QFont font1;
        font1.setPointSize(14);
        labelYMoving->setFont(font1);

        gridGroupMoving->addWidget(labelYMoving, 0, 1, 1, 1);

        labelZMoving = new QLabel(groupMoving);
        labelZMoving->setObjectName(QString::fromUtf8("labelZMoving"));
        labelZMoving->setFont(font1);

        gridGroupMoving->addWidget(labelZMoving, 0, 2, 1, 1);

        labelXMoving = new QLabel(groupMoving);
        labelXMoving->setObjectName(QString::fromUtf8("labelXMoving"));
        labelXMoving->setFont(font1);

        gridGroupMoving->addWidget(labelXMoving, 0, 0, 1, 1);

        buttonMoving = new QPushButton(groupMoving);
        buttonMoving->setObjectName(QString::fromUtf8("buttonMoving"));

        gridGroupMoving->addWidget(buttonMoving, 2, 0, 1, 3);

        enterXMoving = new QDoubleSpinBox(groupMoving);
        enterXMoving->setObjectName(QString::fromUtf8("enterXMoving"));
        enterXMoving->setMinimum(-1000.000000000000000);
        enterXMoving->setMaximum(1000.000000000000000);

        gridGroupMoving->addWidget(enterXMoving, 1, 0, 1, 1);

        enterYMoving = new QDoubleSpinBox(groupMoving);
        enterYMoving->setObjectName(QString::fromUtf8("enterYMoving"));
        enterYMoving->setMinimum(-1000.000000000000000);
        enterYMoving->setMaximum(1000.000000000000000);

        gridGroupMoving->addWidget(enterYMoving, 1, 1, 1, 1);


        verticalLayout->addWidget(groupMoving);

        groupTurn = new QGroupBox(centralwidget);
        groupTurn->setObjectName(QString::fromUtf8("groupTurn"));
        groupTurn->setMinimumSize(QSize(249, 173));
        groupTurn->setMaximumSize(QSize(16777215, 173));
        groupTurn->setFont(font);
        gridGroupTurn = new QGridLayout(groupTurn);
        gridGroupTurn->setObjectName(QString::fromUtf8("gridGroupTurn"));
        gridGroupTurn->setHorizontalSpacing(15);
        gridGroupTurn->setVerticalSpacing(20);
        gridGroupTurn->setContentsMargins(10, 10, 10, 10);
        labelZTurn = new QLabel(groupTurn);
        labelZTurn->setObjectName(QString::fromUtf8("labelZTurn"));
        labelZTurn->setFont(font1);

        gridGroupTurn->addWidget(labelZTurn, 0, 2, 1, 1);

        labelYTurn = new QLabel(groupTurn);
        labelYTurn->setObjectName(QString::fromUtf8("labelYTurn"));
        labelYTurn->setFont(font1);

        gridGroupTurn->addWidget(labelYTurn, 0, 1, 1, 1);

        enterZTurn = new QDoubleSpinBox(groupTurn);
        enterZTurn->setObjectName(QString::fromUtf8("enterZTurn"));
        enterZTurn->setMinimum(-1000.000000000000000);
        enterZTurn->setMaximum(1000.000000000000000);

        gridGroupTurn->addWidget(enterZTurn, 1, 2, 1, 1);

        labelXTurn = new QLabel(groupTurn);
        labelXTurn->setObjectName(QString::fromUtf8("labelXTurn"));
        labelXTurn->setFont(font1);

        gridGroupTurn->addWidget(labelXTurn, 0, 0, 1, 1);

        enterYTurn = new QDoubleSpinBox(groupTurn);
        enterYTurn->setObjectName(QString::fromUtf8("enterYTurn"));
        enterYTurn->setMinimum(-1000.000000000000000);
        enterYTurn->setMaximum(1000.000000000000000);

        gridGroupTurn->addWidget(enterYTurn, 1, 1, 1, 1);

        enterXTurn = new QDoubleSpinBox(groupTurn);
        enterXTurn->setObjectName(QString::fromUtf8("enterXTurn"));
        enterXTurn->setMinimum(-1000.000000000000000);
        enterXTurn->setMaximum(1000.000000000000000);

        gridGroupTurn->addWidget(enterXTurn, 1, 0, 1, 1);

        buttonTurn = new QPushButton(groupTurn);
        buttonTurn->setObjectName(QString::fromUtf8("buttonTurn"));

        gridGroupTurn->addWidget(buttonTurn, 2, 0, 1, 3);


        verticalLayout->addWidget(groupTurn);

        groupScale = new QGroupBox(centralwidget);
        groupScale->setObjectName(QString::fromUtf8("groupScale"));
        groupScale->setMaximumSize(QSize(16777215, 166));
        groupScale->setFont(font);
        gridGroupScale = new QGridLayout(groupScale);
        gridGroupScale->setObjectName(QString::fromUtf8("gridGroupScale"));
        gridGroupScale->setHorizontalSpacing(15);
        gridGroupScale->setVerticalSpacing(20);
        gridGroupScale->setContentsMargins(10, 10, 10, 10);
        labelZScale = new QLabel(groupScale);
        labelZScale->setObjectName(QString::fromUtf8("labelZScale"));
        labelZScale->setFont(font1);

        gridGroupScale->addWidget(labelZScale, 0, 2, 1, 1);

        enterZScale = new QDoubleSpinBox(groupScale);
        enterZScale->setObjectName(QString::fromUtf8("enterZScale"));
        enterZScale->setMinimum(-1000.000000000000000);
        enterZScale->setMaximum(1000.000000000000000);

        gridGroupScale->addWidget(enterZScale, 1, 2, 1, 1);

        enterYScale = new QDoubleSpinBox(groupScale);
        enterYScale->setObjectName(QString::fromUtf8("enterYScale"));
        enterYScale->setMinimum(-1000.000000000000000);
        enterYScale->setMaximum(1000.000000000000000);

        gridGroupScale->addWidget(enterYScale, 1, 1, 1, 1);

        labelYScale = new QLabel(groupScale);
        labelYScale->setObjectName(QString::fromUtf8("labelYScale"));
        labelYScale->setFont(font1);

        gridGroupScale->addWidget(labelYScale, 0, 1, 1, 1);

        labelXScale = new QLabel(groupScale);
        labelXScale->setObjectName(QString::fromUtf8("labelXScale"));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        labelXScale->setFont(font2);
        labelXScale->setFrameShape(QFrame::NoFrame);
        labelXScale->setFrameShadow(QFrame::Plain);
        labelXScale->setLineWidth(1);
        labelXScale->setMidLineWidth(0);
        labelXScale->setTextFormat(Qt::PlainText);
        labelXScale->setScaledContents(false);
        labelXScale->setWordWrap(false);
        labelXScale->setMargin(0);
        labelXScale->setIndent(-1);

        gridGroupScale->addWidget(labelXScale, 0, 0, 1, 1);

        enterXScale = new QDoubleSpinBox(groupScale);
        enterXScale->setObjectName(QString::fromUtf8("enterXScale"));
        enterXScale->setMinimum(-1000.000000000000000);
        enterXScale->setMaximum(1000.000000000000000);

        gridGroupScale->addWidget(enterXScale, 1, 0, 1, 1);

        buttonScale = new QPushButton(groupScale);
        buttonScale->setObjectName(QString::fromUtf8("buttonScale"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        buttonScale->setFont(font3);

        gridGroupScale->addWidget(buttonScale, 2, 0, 1, 3);


        verticalLayout->addWidget(groupScale);


        horizontalLayout_2->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(665, 612));

        horizontalLayout_2->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1011, 20));
        actionsFile = new QMenu(menubar);
        actionsFile->setObjectName(QString::fromUtf8("actionsFile"));
        actionsInformation = new QMenu(menubar);
        actionsInformation->setObjectName(QString::fromUtf8("actionsInformation"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(actionsFile->menuAction());
        menubar->addAction(actionsInformation->menuAction());
        actionsFile->addSeparator();
        actionsFile->addSeparator();
        actionsFile->addAction(actionSave);
        actionsFile->addAction(actionLoad);
        actionsInformation->addAction(actionInfFile);
        actionsInformation->addAction(actionInfProgram);
        actionsInformation->addAction(actionInfDeveloper);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D Viewer", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        actionInfFile->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\320\275\320\276\320\271 \321\204\320\260\320\271\320\273", nullptr));
        actionInfProgram->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260", nullptr));
        actionInfDeveloper->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272", nullptr));
        groupMoving->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        labelYMoving->setText(QCoreApplication::translate("MainWindow", "dy", nullptr));
        labelZMoving->setText(QCoreApplication::translate("MainWindow", "dz", nullptr));
        labelXMoving->setText(QCoreApplication::translate("MainWindow", "dx", nullptr));
        buttonMoving->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        groupTurn->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        labelZTurn->setText(QCoreApplication::translate("MainWindow", "angle z", nullptr));
        labelYTurn->setText(QCoreApplication::translate("MainWindow", "angle y", nullptr));
        labelXTurn->setText(QCoreApplication::translate("MainWindow", "angle x", nullptr));
        buttonTurn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        groupScale->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        labelZScale->setText(QCoreApplication::translate("MainWindow", "kz", nullptr));
        labelYScale->setText(QCoreApplication::translate("MainWindow", "ky", nullptr));
        labelXScale->setText(QCoreApplication::translate("MainWindow", "kx", nullptr));
        buttonScale->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\274\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        actionsFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        actionsInformation->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

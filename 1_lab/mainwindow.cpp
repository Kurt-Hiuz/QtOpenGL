#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("ПСВУ. 1 Лаба. Певень Дмитрий");
    setMinimumSize(1000,800);

    openGL_painter = new OGLPainter(this);
    openGL_painter->setMinimumSize(800, 600);

    appMenu = new AppMenu(this);
    appMenu->createInterface();

    addNewFigureDialogWindow = new AddNewFigureDialogWindow();

    QHBoxLayout* horizontalLayout = new QHBoxLayout();

    horizontalLayout->addWidget(openGL_painter);
    horizontalLayout->addWidget(appMenu);

    ui->centralwidget->setLayout(horizontalLayout);

    connect(appMenu->getClearPainterBtn(), &QPushButton::clicked, openGL_painter, &OGLPainter::clearSpace);
    connect(appMenu->getAddNewFigureBtn(), &QPushButton::clicked, this, &MainWindow::showAddNewFigureDialogWindow);
    connect(addNewFigureDialogWindow,  &AddNewFigureDialogWindow::newFigureCreated, this, &MainWindow::paintNewFigure);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAddNewFigureDialogWindow()
{
    addNewFigureDialogWindow->createInterface();
    addNewFigureDialogWindow->exec();
}

void MainWindow::paintNewFigure(Figure *newFigure)
{
    if(!newFigure){
        qDebug() << "Ошибка получения фигуры";
        return;
    }

    if(newFigure->getPoints() && newFigure->getPoints()->size() > 0) {
        openGL_painter->repaint(newFigure);
        return;
    }

    qDebug() << "Фигура не содержит точек!";
    // delete newFigure;
}

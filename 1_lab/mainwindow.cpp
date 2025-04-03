#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "oglpainter/oglpainter.h"

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

    OGLPainter* openGL_painter = new OGLPainter(this);
    openGL_painter->setMinimumSize(800, 600);

    appMenu = new AppMenu(this);
    appMenu->createInterface();

    addNewPointDialogWindow = new AddNewFigureDialogWindow();

    QHBoxLayout* horizontalLayout = new QHBoxLayout();

    horizontalLayout->addWidget(openGL_painter);
    horizontalLayout->addWidget(appMenu);

    ui->centralwidget->setLayout(horizontalLayout);

    connect(appMenu->getClearPainterBtn(), &QPushButton::clicked, openGL_painter, &OGLPainter::clearSpace);
    connect(appMenu->getAddNewFigureBtn(), &QPushButton::clicked, this, &MainWindow::showAddNewFigureDialogWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAddNewFigureDialogWindow()
{
    addNewPointDialogWindow->createInterface();
    addNewPointDialogWindow->exec();
}

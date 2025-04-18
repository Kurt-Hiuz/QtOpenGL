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
    connect(appMenu->getScalePainterComboBox(), &QComboBox::currentIndexChanged, this, &MainWindow::changeScalePainter);
    connect(appMenu->getAngleXSceneSlider(), &QSlider::valueChanged, this, &MainWindow::rotateXScene);
    connect(appMenu->getAngleYSceneSlider(), &QSlider::valueChanged, this, &MainWindow::rotateYScene);
    connect(appMenu->getAngleZSceneSlider(), &QSlider::valueChanged, this, &MainWindow::rotateZScene);
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

    if(newFigure->getIsCircle()){
        openGL_painter->repaint(newFigure);
        return;
    }

    qDebug() << "Фигура не содержит точек!";
    // delete newFigure;
}

void MainWindow::changeScalePainter()
{
    openGL_painter->setNewScale(appMenu->getScalePainterComboBox()->currentData().toFloat());
}

void MainWindow::rotateYScene(int angleY)
{
    openGL_painter->setNewAngelYScene(angleY);
}

void MainWindow::rotateZScene(int angleZ)
{
    openGL_painter->setNewAngelZScene(angleZ);
}

void MainWindow::rotateXScene(int angleX)
{
    openGL_painter->setNewAngelXScene(angleX);
}

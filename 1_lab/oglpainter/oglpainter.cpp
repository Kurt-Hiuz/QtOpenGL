#include "oglpainter.h"

OGLPainter::OGLPainter(QWidget *parent) : QOpenGLWidget(parent)
{
    figuresHandler = new FiguresHandler();
}

OGLPainter::~OGLPainter()
{

}

void OGLPainter::repaint(Figure *newFigure)
{
    figuresHandler->addNewFigure(newFigure);
    update();
}

void OGLPainter::clearSpace()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // figuresHandler->deleteFigures();
    qDebug() << "плоскость очищена";
}

void OGLPainter::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1, 0.5, 1, 1);
}

void OGLPainter::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(figuresHandler->countFigures() == 0) {
        qDebug() << "Фигур нет";
        return;
    }

    for(int index = 0; index < figuresHandler->countFigures(); index++){
        Figure *currentFigure = figuresHandler->getFigure(index);
        if(!currentFigure) continue;

        qDebug() << "Взята фигура: (" << index << ") " << currentFigure;

        glBegin(currentFigure->getPaintMode());

        if(currentFigure->getDimensional() == 2){

            glColor3f(1.0f, 0.5f, 0.0f);

            QList<Point*> *figurePoints = currentFigure->getPoints();

            for(int jndex = 0; jndex < figurePoints->size(); jndex++){
                Point* nextPoint = figurePoints->at(jndex);

                if(nextPoint){
                    glVertex2f(nextPoint->get_x(), nextPoint->get_y());
                    qDebug() << "Точка:" << nextPoint->get_x() << nextPoint->get_y();
                }
            }

            qDebug() << "Фигура " << currentFigure << " отрисована";
        }
        glEnd();
    }
    // figuresHandler->paintFigures();

    // if(this->isTriangle){

        glBegin(4);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);

        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glEnd();


    //     glBegin(GL_POLYGON);
    //     glColor3f(1.0f, 0.5f, 0.0f);
    //     glVertex3f(-0.5f, 0.5f, 0.0f);

    //     glColor3f(1.0f, 0.0f, 0.0f);
    //     glVertex3f(0.5f, 0.5f, 0.0f);

    //     glColor3f(1.0f, 0.0f, 1.0f);
    //     glVertex3f(0.5f, -0.5f, 0.0f);

    //     glColor3f(1.0f, 0.0f, 1.0f);
    //     glVertex3f(-0.5f, -0.5f, 0.0f);
    //     glEnd();

    //     glBegin(GL_TRIANGLES);
    //     glColor3f(1.0f, 0.0f, 0.0f);
    //     glVertex3f(-0.5f, 0.5f, 0.0f);

    //     glColor3f(1.0f, 0.0f, 0.0f);
    //     glVertex3f(0.5f, 0.5f, 0.0f);

    //     glColor3f(1.0f, 0.0f, 1.0f);
    //     glVertex3f(0.0f, 0.0f, 0.0f);
    //     glEnd();
    // }
}

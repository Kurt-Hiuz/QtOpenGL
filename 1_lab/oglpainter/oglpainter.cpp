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
    figuresHandler->deleteFigures();
    update();
    qDebug() << "плоскость очищена";
}

void OGLPainter::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1, 0.5, 1, 1);
}

void OGLPainter::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float zoom = 10.0f; // Полотно увеличено в 10 раз
    glOrtho(0.0,zoom*1.0,0.0,zoom*1.0,zoom*-1.0,zoom*1.0);

    // glBegin(4);
    // glColor3f(1.0f, 0.0f, 1.0f);
    // glVertex3f(3.0f, 3.0f, 0.0f);

    // glColor3f(0.0f, 1.0f, 0.0f);
    // glVertex3f(3.0f, 5.0f, 0.0f);

    // glColor3f(1.0f, 0.0f, 1.0f);
    // glVertex3f(5.0f, 3.0f, 0.0f);
    // glEnd();

    if(figuresHandler->countFigures() == 0) {
        qDebug() << "Фигур нет";
        return;
    }

    for(int index = 0; index < figuresHandler->countFigures(); index++){
        Figure *currentFigure = figuresHandler->getFigure(index);
        if(!currentFigure) continue;

        qDebug() << "Взята фигура: (" << index << ") " << currentFigure;

        paintFigure(currentFigure);

    }

    //  тестовая фигура для отработки рисования
        glBegin(4);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);

        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glEnd();
}

void OGLPainter::paintFigure(Figure *currentFigureToPaint)
{
    glBegin(currentFigureToPaint->getPaintMode());

    if(currentFigureToPaint->getDimensional() == 2){
        QColor *currentBackgroundColor = currentFigureToPaint->getBackgroundColor();
        glColor3f(currentBackgroundColor->redF(), currentBackgroundColor->greenF(), currentBackgroundColor->blueF());

        QList<Point*> *figurePoints = currentFigureToPaint->getPoints();

        if(currentFigureToPaint->getIsCircle()){
            paintCircle(figurePoints->value(0)->get_x(), figurePoints->value(0)->get_y(), currentFigureToPaint->getRadius());
            qDebug() << "Отрисован круг " << currentFigureToPaint;
            qDebug() << "Центр: " << figurePoints->value(0)->get_x() << "; " << figurePoints->value(0)->get_y() << "| Радиус " << currentFigureToPaint->getRadius();
            return;
        }

        for(int jndex = 0; jndex < figurePoints->size(); jndex++){
            Point* nextPoint = figurePoints->at(jndex);

            if(nextPoint){
                glVertex2f(nextPoint->get_x(), nextPoint->get_y());
                qDebug() << "Точка:" << nextPoint->get_x() << nextPoint->get_y();
            }
        }

        qDebug() << "Фигура " << currentFigureToPaint << " отрисована";
        glEnd();

        paintBorder(currentFigureToPaint, figurePoints);
    }
}

void OGLPainter::paintCircle(float centerX, float centerY, float radius)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 0; i < 100000; i++) {
        float angle = 2.0f * M_PI * float(i) / float(100000);
        glVertex2f(centerX + radius * cosf(angle),  centerY + radius * sinf(angle));
    }
    glEnd();
}

void OGLPainter::paintBorder(Figure *figureToPaint, QList<Point *> *figuresBorderPoints)
{
    if(figureToPaint->getBorderWidth() <= 0) {return;}

    if(figureToPaint->getBorderWidth() > 0){
        glLineWidth(figureToPaint->getBorderWidth());
        QColor *currentBorderColor = figureToPaint->getBorderColor();
        glColor3f(currentBorderColor->redF(), currentBorderColor->greenF(), currentBorderColor->blueF());

        glBegin(GL_LINE_LOOP);
        for(int jndex = 0; jndex < figuresBorderPoints->size(); jndex++){
            Point* nextPoint = figuresBorderPoints->at(jndex);

            if(nextPoint){
                glVertex2f(nextPoint->get_x(), nextPoint->get_y());
                qDebug() << "Точка рамки:" << nextPoint->get_x() << nextPoint->get_y();
            }
        }
        glEnd();

        qDebug() << "Рамка фигуры " << figureToPaint << " отрисована";
    }
}

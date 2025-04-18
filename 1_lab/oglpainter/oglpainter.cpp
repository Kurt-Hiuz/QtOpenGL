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

void OGLPainter::setNewScale(float newScale)
{
    this->scalePainter = newScale;
    update();
}

void OGLPainter::setNewAngelXScene(float angleX)
{
    // glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    this->angleRotateXScene = angleX;
    qDebug() << "Установлен новый X угол " << angleX;
    update();
}

void OGLPainter::setNewAngelYScene(float angleY)
{
    // glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    this->angleRotateYScene = angleY;
    qDebug() << "Установлен новый Y угол " << angleY;
    update();
}

void OGLPainter::setNewAngelZScene(float angleZ)
{
    // glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    this->angleRotateZScene = angleZ;
    qDebug() << "Установлен новый Z угол " << angleZ;
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
    glTranslatef(5.0f, 5.0f, 5.0f);
}

void OGLPainter::paintGL()
{
    qDebug() << "Сцена обновлена";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(angleRotateXScene, 1.0f, 0.0f, 0.0f);
    glRotatef(angleRotateYScene, 0.0f, 1.0f, 0.0f);
    glRotatef(angleRotateZScene, 0.0f, 0.0f, 1.0f);
    glOrtho(0.0,scalePainter*1.0,0.0,scalePainter*1.0,scalePainter*-1.0,scalePainter*1.0);

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
    if(currentFigureToPaint->getDimensional() == 2){
        paint2DFigure(currentFigureToPaint);
        return;
    }

    if(currentFigureToPaint->getDimensional() == 3){
        paint3DFigure(currentFigureToPaint);
        return;
    }
}

void OGLPainter::paint2DFigure(Figure *current2DFigureToPaint)
{
    QColor *currentBackgroundColor = current2DFigureToPaint->getBackgroundColor();
    glColor3f(currentBackgroundColor->redF(), currentBackgroundColor->greenF(), currentBackgroundColor->blueF());

    QList<Point*> *figurePoints = current2DFigureToPaint->getPoints();

    if(current2DFigureToPaint->getIsCircle()){
        paintCircle(current2DFigureToPaint);
        qDebug() << "Отрисован круг " << current2DFigureToPaint;
        qDebug() << "Центр: " << figurePoints->value(0)->get_x() << "; " << figurePoints->value(0)->get_y() << "| Радиус " << current2DFigureToPaint->getRadius();
        paintCircleBorder(current2DFigureToPaint);
        return;
    }

    glBegin(current2DFigureToPaint->getPaintMode());
    for(int jndex = 0; jndex < figurePoints->size(); jndex++){
        Point* nextPoint = figurePoints->at(jndex);

        if(nextPoint){
            glVertex2f(nextPoint->get_x(), nextPoint->get_y());
            qDebug() << "Точка:" << nextPoint->get_x() << nextPoint->get_y();
        }
    }

    qDebug() << "Фигура " << current2DFigureToPaint << " отрисована";
    glEnd();

    paint2DBorder(current2DFigureToPaint, figurePoints);
}

void OGLPainter::paint3DFigure(Figure *current3DFigureToPaint)
{
    QColor *currentBackgroundColor = current3DFigureToPaint->getBackgroundColor();
    glColor3f(currentBackgroundColor->redF(), currentBackgroundColor->greenF(), currentBackgroundColor->blueF());

    QList<Point*> *figurePoints = current3DFigureToPaint->getPoints();

    //  TODO: сделать отрисовку сферы

    // if(current3DFigureToPaint->getIsCircle()){
    //     paintCircle(current3DFigureToPaint);
    //     qDebug() << "Отрисован круг " << current3DFigureToPaint;
    //     qDebug() << "Центр: " << figurePoints->value(0)->get_x() << "; " << figurePoints->value(0)->get_y() << "| Радиус " << current3DFigureToPaint->getRadius();
    //     paintCircleBorder(current3DFigureToPaint);
    //     return;
    // }

    glBegin(current3DFigureToPaint->getPaintMode());
    for(int jndex = 0; jndex < figurePoints->size(); jndex++){
        Point* nextPoint = figurePoints->at(jndex);

        if(nextPoint){
            glVertex3f(nextPoint->get_x(), nextPoint->get_y(), nextPoint->get_z());
            qDebug() << "Точка:" << nextPoint->get_x() << nextPoint->get_y() << nextPoint->get_z();
        }
    }

    qDebug() << "Фигура " << current3DFigureToPaint << " отрисована";
    glEnd();

    paint2DBorder(current3DFigureToPaint, figurePoints);
}

void OGLPainter::paintCircle(Figure *circleToPaint)
{
    QList<Point*> *ciclePoints = circleToPaint->getPoints();

    float centerX = ciclePoints->value(0)->get_x();
    float centerY = ciclePoints->value(0)->get_y();

    float radius = circleToPaint->getRadius();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(ciclePoints->value(0)->get_x(), centerY);

    for (int i = 0; i < 100000; i++) {
        float angle = 2.0f * M_PI * float(i) / float(100000);
        glVertex2f(centerX + radius * cosf(angle),  centerY + radius * sinf(angle));
    }
    glEnd();
}

void OGLPainter::paintCircleBorder(Figure *circleToPaint)
{
    QColor *borderColor = circleToPaint->getBorderColor();
    glColor3f(borderColor->redF(), borderColor->greenF(), borderColor->blueF());

    QList<Point*> *ciclePoints = circleToPaint->getPoints();

    float centerX = ciclePoints->value(0)->get_x();
    float centerY = ciclePoints->value(0)->get_y();

    float radius = circleToPaint->getRadius();

    glLineWidth(circleToPaint->getBorderWidth());

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100000; i++) {
        float angle = 2.0f * M_PI * float(i) / 100000.0f;
        glVertex2f(centerX + radius * cosf(angle), centerY + radius * sinf(angle));
    }
    glEnd();
}

void OGLPainter::paint2DBorder(Figure *figureToPaint, QList<Point *> *figuresBorderPoints)
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

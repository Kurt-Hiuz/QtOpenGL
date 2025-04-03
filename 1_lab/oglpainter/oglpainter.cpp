#include "oglpainter.h"

OGLPainter::OGLPainter(QWidget *parent) : QOpenGLWidget(parent)
{

}

OGLPainter::~OGLPainter()
{

}

void OGLPainter::clearSpace()
{
    isTriangle = false;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    update();
}

void OGLPainter::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1, 1, 1, 1);
}

void OGLPainter::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(this->isTriangle){
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex3f(-0.5f, 0.5f, 0.0f);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);

        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);

        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);

        glEnd();
    }
}

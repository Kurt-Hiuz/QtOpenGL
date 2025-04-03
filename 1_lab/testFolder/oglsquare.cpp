#include "oglsquare.h"

OGLSquare::OGLSquare(QWidget *parent) : QOpenGLWidget(parent)
{

}

OGLSquare::~OGLSquare()
{

}

void OGLSquare::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0.5, 1, 1, 1);
}

void OGLSquare::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

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

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);

    glEnd();
}

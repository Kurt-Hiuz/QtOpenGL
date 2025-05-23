#include "nooglsquare2.h"

NoOGLSquare2::NoOGLSquare2(QWidget *parent) : QOpenGLWidget(parent)
{

}

NoOGLSquare2::~NoOGLSquare2()
{

}

void NoOGLSquare2::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0.5, 1, 1, 1);
}

void NoOGLSquare2::paintGL()
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

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);

    glEnd();
}

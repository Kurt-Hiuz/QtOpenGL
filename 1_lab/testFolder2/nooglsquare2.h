#ifndef NOOGLSQUARE2_H
#define NOOGLSQUARE2_H

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class NoOGLSquare2 : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    NoOGLSquare2(QWidget *parent = nullptr);
    ~NoOGLSquare2();

protected:
    void initializeGL();
    void paintGL();
};

#endif // NOOGLSQUARE2_H

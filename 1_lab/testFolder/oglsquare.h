#ifndef OGLSQUARE_H
#define OGLSQUARE_H

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OGLSquare : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OGLSquare(QWidget *parent = nullptr);
    ~OGLSquare();

protected:
    void initializeGL();
    void paintGL();
};

#endif // OGLSQUARE_H

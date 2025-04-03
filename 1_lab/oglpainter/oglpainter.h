#ifndef OGLPAINTER_H
#define OGLPAINTER_H

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class OGLPainter : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OGLPainter(QWidget* parent = nullptr);
    ~OGLPainter();

public slots:
    void clearSpace();

protected:
    void initializeGL();
    void paintGL();

private:
    bool isTriangle = true;
};

#endif // OGLPAINTER_H

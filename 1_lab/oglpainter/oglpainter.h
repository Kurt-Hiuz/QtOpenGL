#ifndef OGLPAINTER_H
#define OGLPAINTER_H

#include <QObject>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "oglpainter/figuresHandler/figureshandler.h"

class OGLPainter : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OGLPainter(QWidget* parent = nullptr);
    ~OGLPainter();

    void repaint(Figure *newFigure);

public slots:
    void clearSpace();

protected:
    void initializeGL();
    void paintGL();

private:
    FiguresHandler *figuresHandler;
};

#endif // OGLPAINTER_H

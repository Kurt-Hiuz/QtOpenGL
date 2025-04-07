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
    void setNewScale(float newScale);

public slots:
    void clearSpace();

protected:
    void initializeGL();
    void paintGL();

private:
    float scalePainter = 10.0f; // Полотно увеличено в 10 раз по умолчанию
    FiguresHandler *figuresHandler;
    void paintFigure(Figure *currentFigureToPaint);
    void paintCircle(float centerX, float centerY, float radius);
    void paintBorder(Figure *figureToPaint, QList<Point*> *figuresBorderPoints);
};

#endif // OGLPAINTER_H

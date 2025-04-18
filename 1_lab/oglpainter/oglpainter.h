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
    void setNewAngelXScene(float angleX);
    void setNewAngelYScene(float angleY);
    void setNewAngelZScene(float angleZ);

public slots:
    void clearSpace();

protected:
    void initializeGL();
    void paintGL();

private:
    float scalePainter = 10.0f; // Полотно увеличено в 10 раз по умолчанию
    float rotateScene = 0.0f;
    float angleRotateXScene = 0.0f;
    float angleRotateYScene = 0.0f;
    float angleRotateZScene = 0.0f;
    FiguresHandler *figuresHandler;
    void paintFigure(Figure *currentFigureToPaint);
    void paint2DFigure(Figure *current2DFigureToPaint);
    void paint3DFigure(Figure *current3DFigureToPaint);
    void paintCircle(Figure *circleToPaint);
    void paintCircleBorder(Figure *circleToPaint);
    void paint2DBorder(Figure *figureToPaint, QList<Point*> *figuresBorderPoints);
};

#endif // OGLPAINTER_H

#ifndef FIGURE_H
#define FIGURE_H

#include <QList>
#include <GL/gl.h>

#include "oglpainter/point/point.h"

class Figure
{
public:
    Figure();
    Figure(Point *xpos, Point *ypos);
    Figure(Point *xpos, Point *ypos, Point *zpos);
    Figure(Point *xpos, Point *ypos, Point *zpos, Point *wpos);
    ~Figure();

    void setPaintMode(GLenum newMode);
    GLenum getPaintMode();
    void setBorderWidth(int newBorderWidth);
    void setDimensional(int newDimensional);
    int getDimensional();
    QList<Point*>* getPoints();
    void addNewPoint(Point *newPoint);
    void paint();
    void paint2f();
    void paint3f();
    void paint4f();

    QString toDegug();

private:
    QList<Point*> *points = new QList<Point*>();
    int borderWidth;
    float borderColor;
    float backgroundColor;
    int dimensional;
    GLenum paintMode;
};

#endif // FIGURE_H

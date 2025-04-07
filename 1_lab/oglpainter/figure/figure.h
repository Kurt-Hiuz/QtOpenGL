#ifndef FIGURE_H
#define FIGURE_H

#include <QList>
#include <GL/gl.h>
#include <QColor>

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
    int getBorderWidth();

    void setDimensional(int newDimensional);
    int getDimensional();

    void setBackgroundColor(QColor *newColor);
    QColor *getBackgroundColor();

    void setBorderColor(QColor *newColor);
    QColor *getBorderColor();

    void addNewPoint(Point *newPoint);
    QList<Point*>* getPoints();

    void setIsCicle(bool isItCircle);
    bool getIsCircle();

    void setCenter(Point *newCircleCenter);
    Point* getCenter();

    void setRadius(float newRadius);
    float getRadius();
    // void paint();
    // void paint2f();
    // void paint3f();
    // void paint4f();

    QString toDegug();

private:
    QList<Point*> *points = new QList<Point*>();
    int borderWidth;
    QColor *borderColor;
    QColor *backgroundColor;
    int dimensional;
    GLenum paintMode;
    bool isCircle = false;
    Point *centerCircle;
    int radius;
};

#endif // FIGURE_H

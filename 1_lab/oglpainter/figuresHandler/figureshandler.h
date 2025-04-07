#ifndef FIGURESHANDLER_H
#define FIGURESHANDLER_H

#include <QList>

#include "oglpainter/figure/figure.h"

class FiguresHandler
{
public:
    FiguresHandler();
    ~FiguresHandler();

    void addNewFigure(Figure *newFigure);
    Figure* getFigure(int index);
    void deleteFigures();
    int countFigures();

private:
    QList<Figure*> *figuresList = new QList<Figure*>();
};

#endif // FIGURESHANDLER_H

#include "figureshandler.h"
#include "qdebug.h"

FiguresHandler::FiguresHandler() {}

FiguresHandler::~FiguresHandler()
{
    // qDeleteAll(*figuresList);
    // delete figuresList;
}

void FiguresHandler::addNewFigure(Figure *newFigure)
{
    figuresList->append(newFigure);
    qDebug() << "добавлена новая фигура по ссылке:" << newFigure;
    qDebug() << "Новая фигура: " << newFigure->toDegug();
}

Figure* FiguresHandler::getFigure(int index)
{
    return figuresList->value(index);
}

void FiguresHandler::deleteFigures()
{
    qDebug() << "без очистки";
    figuresList->clear();
    // for(Figure *someFigure : *figuresList){
    //     delete someFigure;
    // }
}

int FiguresHandler::countFigures()
{
    return figuresList->count();
}

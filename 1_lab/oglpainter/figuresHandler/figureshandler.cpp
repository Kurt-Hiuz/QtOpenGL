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
    // for(Figure *someFigure : *figuresList){
    //     delete someFigure;
    // }
}

void FiguresHandler::paintFigures()
{
    for(int index = 0; index < figuresList->length(); index++){
        figuresList->value(index)->paint();
        qDebug() << "Фигура " << figuresList->value(index) << " отрисована";
    }
    qDebug() << "Все фигуры отрисованы";
    // for(Figure *figure : *figuresList){
    //     figure->paint();
    // }
}

int FiguresHandler::countFigures()
{
    return figuresList->count();
}

#include "figure.h"
#include "qdebug.h"

Figure::Figure(){}

Figure::Figure(Point *xpos, Point *ypos) {
    addNewPoint(xpos);
    addNewPoint(ypos);
}

Figure::Figure(Point *xpos, Point *ypos, Point *zpos)
{
    addNewPoint(xpos);
    addNewPoint(ypos);
    addNewPoint(zpos);
}

Figure::Figure(Point *xpos, Point *ypos, Point *zpos, Point *wpos)
{
    addNewPoint(xpos);
    addNewPoint(ypos);
    addNewPoint(zpos);
    addNewPoint(wpos);
}

Figure::~Figure()
{
    // qDeleteAll(*points);
    // delete points;
}

void Figure::setPaintMode(GLenum newMode)
{
    this->paintMode = newMode;

    glColor3f(1.0f, 0.5f, 0.0f);                                                                                        // ОПРЕДЕЛЕНИЕ НАЧАЛЬНОГО ЦВЕТА
}

GLenum Figure::getPaintMode()
{
    return this->paintMode;
}

void Figure::setBorderWidth(int newBorderWidth)
{
    borderWidth = newBorderWidth;
}

int Figure::getBorderWidth()
{
    return this->borderWidth;
}

void Figure::setDimensional(int newDimensional)
{
    this->dimensional = newDimensional;
}

int Figure::getDimensional()
{
    return this->dimensional;
}

void Figure::setBackgroundColor(QColor *newColor)
{
    this->backgroundColor = newColor;
}

QColor *Figure::getBackgroundColor()
{
    return this->backgroundColor;
}

void Figure::setBorderColor(QColor *newColor)
{
    this->borderColor = newColor;
}

QColor *Figure::getBorderColor()
{
    return this->borderColor;
}

QList<Point *> *Figure::getPoints()
{
    return points;
}

void Figure::setIsCicle(bool isItCircle)
{
    this->isCircle = isItCircle;
}

bool Figure::getIsCircle()
{
    return this->isCircle;
}

void Figure::setCenter(Point *newCircleCenter)
{
    this->centerCircle = newCircleCenter;
}

Point *Figure::getCenter()
{
    return this->centerCircle;
}

void Figure::setRadius(float newRadius)
{
    this->radius = newRadius;
}

float Figure::getRadius()
{
    return this->radius;
}

void Figure::addNewPoint(Point *newPoint)
{
    points->append(newPoint);
}

// void Figure::paint()
// {
//     if(dimensional == 2){
//         paint2f();
//         return;
//     }

//     if(dimensional == 3){
//         paint3f();
//         return;
//     }

//     if(dimensional == 4){
//         paint4f();
//         return;
//     }
// }

// void Figure::paint2f()
// {
//     glBegin(paintMode);
//     for(int index = 0; index < points->length(); index++){
//         glVertex2f(points->value(index)->get_x(), points->value(index)->get_y());
//         // TODO: почему-то регистрируются три подряд одни и те же точки
//         qDebug() << "координата икс: " << points->value(index)->get_x() << "координата игрек: " << points->value(index)->get_y();
//     }
//     glEnd();
//     // for(Point *point : *points){
//     //     glVertex2f(point->get_x(), point->get_y());
//     // }

// }

// void Figure::paint3f()
// {
//     for(Point *point : *points){
//         glVertex3f(point->get_x(), point->get_y(), point->get_z());
//     }
// }

// void Figure::paint4f()
// {
//     for(Point *point : *points){
//         glVertex4f(point->get_x(), point->get_y(), point->get_z(), point->get_w());
//     }
// }

QString Figure::toDegug()
{
    return QString("Измерение: "+QString::number(dimensional)+"Ширина рамки: "+QString::number(borderWidth)+".\t Количество точек:"+QString::number(points->length())+".\t Координата Х1:"+QString::number(points->value(0)->get_x()));
}

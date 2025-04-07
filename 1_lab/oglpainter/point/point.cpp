#include "point.h"

Point::Point() {}

Point::Point(float xpos, float ypos)
{
    this->x = xpos;
    this->y = ypos;
}

Point::Point(float xpos, float ypos, float zpos)
{
    this->x = xpos;
    this->y = ypos;
    this->z = zpos;
}

Point::Point(float xpos, float ypos, float zpos, float wpos)
{
    this->x = xpos;
    this->y = ypos;
    this->z = zpos;
    this->w = wpos;
}

Point::~Point()
{

}

float Point::get_x()
{
    return x;
}

float Point::get_y()
{
    return y;
}

float Point::get_z()
{
    return z;
}

float Point::get_w()
{
    return w;
}

void Point::set_x(float newX)
{
    this->x = newX;
}

void Point::set_y(float newY)
{
    this->y = newY;
}

void Point::set_z(float newZ)
{
    this->z = newZ;
}

void Point::set_w(float newW)
{
    this->w = newW;
}

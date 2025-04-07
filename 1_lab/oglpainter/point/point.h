#ifndef POINT_H
#define POINT_H

#include <QPointF>

class Point : public QPointF
{
public:
    Point();
    Point(float xpos, float ypos);
    Point(float xpos, float ypos, float zpos);
    Point(float xpos, float ypos, float zpos, float wpos);
    ~Point();

    float get_x();
    float get_y();
    float get_z();
    float get_w();

    void set_x(float newX);
    void set_y(float newX);
    void set_z(float newX);
    void set_w(float newX);

private:
    float x = 0;
    float y = 0;
    float z = 0;
    float w = 0;
};

#endif // POINT_H

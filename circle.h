#pragma once
#include"IShape.h"
#include"QPoint"
class Circle:public IShape
{
public:
    Circle();
    void draw(QPainter&) const override;
    QPoint firstPoint() const {return first_point;}
    QPoint secondPoint()const {return second_point;}
    void setFirstPoint(QPoint f){first_point = f;}
    void setSecondPoint(QPoint f){second_point = f;}
    ~Circle();

private:
    QPoint first_point;
    QPoint second_point;


};

#pragma once
#include"IShape.h"
#include"QPoint"
class Triangle:public IShape//треугольник описывается левой верхней и правой нижней точкой прямоугольника в который он вписывается
{
public:
    Triangle(int id);
    void draw(QPainter&) const override;
    QPoint getCenter() const override;
    bool isPointInShape(QPoint) const override;
    void moveShape(QPoint) override;
    void serialize(QDataStream&) const override;
    void deserialize(QDataStream&)override;
    QPoint firstPoint() const {return first_point;}
    QPoint secondPoint()const {return second_point;}
    void setFirstPoint(QPoint f){first_point = f;}
    void setSecondPoint(QPoint f){second_point = f;}
    ~Triangle();

private:
    QPoint first_point;
    QPoint second_point;


};


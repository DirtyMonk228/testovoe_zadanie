#pragma once
#include<QPainter>
class IShape{
public:
    IShape(int _id):id(_id){}
    virtual void draw(QPainter&) const = 0;
    virtual ~IShape() = default;
    virtual QPoint getCenter() const = 0;
    virtual bool isPointInShape(QPoint) const = 0;
    int getId(){return id;}

private:
    int id;
};

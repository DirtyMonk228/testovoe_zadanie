#pragma once
#include<QPainter>
#include"ISerializable.h"
#include<cmath>
class IShape:public ISerializable{
public:
    IShape(int _id):ISerializable(),id(_id){}
    virtual void draw(QPainter&) const = 0;
    virtual ~IShape() = default;
    virtual QPoint getCenter() const = 0;
    virtual bool isPointInShape(QPoint) const = 0;
    virtual void moveShape(QPoint) = 0;
    virtual double getArea() const = 0;
    void setType(const QString& _type){type =_type;}
    QString getType()const {return type;}
    int getId()const {return id;}
    void setId(int _id){id=_id;}

private:
    int id;
    QString type;
};

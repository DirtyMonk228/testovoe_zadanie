#pragma once
#include<QPainter>
class IShape{
public:
    virtual void draw(QPainter&) const = 0;
    virtual ~IShape() = default;
};

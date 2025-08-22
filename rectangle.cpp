#include "rectangle.h"

Rectangle::Rectangle():IShape() {}

void Rectangle::draw(QPainter& painter)const{
    QRect tmp_rect = QRect(first_point,second_point);
    painter.drawRect(tmp_rect);
}

Rectangle::~Rectangle(){}

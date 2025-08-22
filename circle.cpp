#include "circle.h"

Circle::Circle():IShape() {}

void Circle::draw(QPainter& painter)const{
    QRect tmp_rect = QRect(first_point,second_point);
    painter.drawEllipse(tmp_rect);
}

Circle::~Circle(){}

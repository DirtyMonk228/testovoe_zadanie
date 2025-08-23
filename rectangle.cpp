#include "rectangle.h"

Rectangle::Rectangle(int id):IShape(id) {}

void Rectangle::draw(QPainter& painter)const{
    QRect tmp_rect = QRect(first_point,second_point);
    painter.drawRect(tmp_rect);
}

QPoint Rectangle::getCenter() const{
    return (first_point + second_point) / 2;
}

bool Rectangle::isPointInShape(QPoint a) const{
    QRect tmp_rect(first_point,second_point);
    return tmp_rect.contains(a);
}
Rectangle::~Rectangle(){}

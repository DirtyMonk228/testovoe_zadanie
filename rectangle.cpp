#include "rectangle.h"

Rectangle::Rectangle(int id):IShape(id) {
    setType("Rectangle");
}
void Rectangle::moveShape(QPoint move_point){
    first_point+= move_point;
    second_point+=move_point;
}
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

void Rectangle::serialize(QDataStream& out) const{
    out<<getType()<<getId()<<first_point<<second_point;
}

void Rectangle::deserialize(QDataStream& in){
    int id;
    in>>id;setId(id);
    in>>first_point>>second_point;
}
Rectangle::~Rectangle(){}

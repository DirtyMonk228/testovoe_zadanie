#include "triangle.h"
Triangle::Triangle():IShape(){}
void Triangle::draw(QPainter& painter) const {
    QPolygon triangle;
    QPoint first_p = firstPoint();
    QPoint second_p = secondPoint();
    triangle<<QPoint(first_p.x()+(first_p.x()+second_p.x())/2,first_p.y())//верхняя вершина треугольника
             <<QPoint(first_p.x(),second_p.y())<<QPoint(second_p);
    painter.drawPolygon(triangle);
}

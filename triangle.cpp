#include "triangle.h"
Triangle::Triangle(int id):IShape(id){}
void Triangle::draw(QPainter& painter) const {
    QPolygon triangle;
    QPoint first_p = firstPoint();
    QPoint second_p = secondPoint();
    triangle<<QPoint(first_p.x()+(second_p.x()-first_p.x())/2,first_p.y())//верхняя вершина треугольника
             <<QPoint(first_p.x(),second_p.y())<<QPoint(second_p);
    painter.drawPolygon(triangle);
}
QPoint Triangle::getCenter() const{
    return (first_point + second_point) / 2;
    QPoint first_p = QPoint(first_point.x()+(second_point.x()-first_point.x())/2,first_point.y());
    QPoint second_p = QPoint(first_point.x(),second_point.y());
    QPoint third_p = second_point;
    return QPoint(
        (first_p.x() + second_p.x() + third_p.x()) / 3,
        (first_p.y() + second_p.y() + third_p.y()) / 3
        );
}

bool Triangle::isPointInShape(QPoint point)const{
    QPoint a = QPoint(first_point.x()+(second_point.x()-first_point.x())/2,first_point.y());
    QPoint b = QPoint(first_point.x(),second_point.y());
    QPoint c = second_point;
    QPoint v0 = c - a;
    QPoint v1 = b - a;
    QPoint v2 = point - a;


    int dot00 = QPoint::dotProduct(v0, v0);
    int dot01 = QPoint::dotProduct(v0, v1);
    int dot02 = QPoint::dotProduct(v0, v2);
    int dot11 = QPoint::dotProduct(v1, v1);
    int dot12 = QPoint::dotProduct(v1, v2);

    double invDenom = 1.0 / (dot00 * dot11 - dot01 * dot01);
    double u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    double v = (dot00 * dot12 - dot01 * dot02) * invDenom;

    // Точка внутри треугольника, если u >= 0, v >= 0 и u + v <= 1
    return (u >= 0) && (v >= 0) && (u + v <= 1);
}
Triangle::~Triangle(){}

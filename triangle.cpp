#include "triangle.h"
Triangle::Triangle(int id):IShape(id){
    setType("Triangle");
}

void Triangle::moveShape(QPoint move_point){
    first_point+= move_point;
    second_point+=move_point;
}
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



double triangleArea(const QPointF& a, const QPointF& b, const QPointF& c) {
    return std::abs((a.x() * (b.y() - c.y()) +
                     b.x() * (c.y() - a.y()) +
                     c.x() * (a.y() - b.y())) / 2.0);
}

bool Triangle::isPointInShape( QPoint point)const {
    QPoint a = QPoint(first_point.x()+(second_point.x()-first_point.x())/2,first_point.y());
    QPoint b = QPoint(first_point.x(),second_point.y());
    QPoint c = second_point;
    double main_area = triangleArea(a, b, c);

    double area1 = triangleArea(point, a, b);
    double area2 = triangleArea(point, b, c);
    double area3 = triangleArea(point, c, a);


    const double epsilon = 1e-10;
    return std::abs(main_area - (area1 + area2 + area3)) < epsilon;
}
void Triangle::serialize(QDataStream& out) const{
    out<<getType()<<getId()<<first_point<<second_point;
}

void Triangle::deserialize(QDataStream& in){
    int id;
    in>>id;setId(id);
    in>>first_point>>second_point;
}
double Triangle::getArea() const{
    QRect bounding_rect(first_point,second_point);
    return bounding_rect.width()*bounding_rect.height()/2;
}
Triangle::~Triangle(){}

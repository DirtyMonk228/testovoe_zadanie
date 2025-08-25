#include "circle.h"

Circle::Circle(int id):IShape(id) {}


void Circle::moveShape(QPoint move_point){
    first_point+= move_point;
    second_point+=move_point;
}
void Circle::draw(QPainter& painter)const{
    QRect tmp_rect = QRect(first_point,second_point);
    painter.drawEllipse(tmp_rect);
}

QPoint Circle::getCenter() const{
    return (first_point + second_point) / 2;
}

bool Circle::isPointInShape(QPoint point)const {
    QRect bounding_rect = QRect(first_point, second_point).normalized();

    if (bounding_rect.isEmpty()) {
        return false;
    }

    QPoint center = bounding_rect.center();
    double a = bounding_rect.width() / 2.0;
    double b = bounding_rect.height() / 2.0;

    double dx = point.x() - center.x();
    double dy = point.y() - center.y();

    return (dx * dx) / (a * a) + (dy * dy) / (b * b) <= 1.0;
}
Circle::~Circle(){}

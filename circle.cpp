#include "circle.h"

Circle::Circle(int id):IShape(id) {}

void Circle::draw(QPainter& painter)const{
    QRect tmp_rect = QRect(first_point,second_point);
    painter.drawEllipse(tmp_rect);
}

QPoint Circle::getCenter() const{
    return (first_point + second_point) / 2;
}

bool Circle::isPointInShape(QPoint point)const {
    QRect bounding_rect(first_point,second_point);

    if (bounding_rect.isEmpty() || bounding_rect.isNull()) {
        return false;
    }

    QPoint center = bounding_rect.center();
    int a = bounding_rect.width() / 2;
    int b = bounding_rect.height() / 2;

    if (a <= 0 || b <= 0) {
        return false;
    }

    int dx = point.x() - center.x();
    int dy = point.y() - center.y();

    return (dx * dx * b * b + dy * dy * a * a) <= (a * a * b * b);
}
Circle::~Circle(){}

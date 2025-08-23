#include "connection.h"
#include"screen.h"
Connection::Connection(){}

void Connection::draw(QPainter& painter,Screen* screen)const {
    painter.drawLine(start,end);
}

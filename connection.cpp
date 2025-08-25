#include "connection.h"
#include"screen.h"
Connection::Connection(){}

void Connection::draw(QPainter& painter,Screen* screen)const {
    if(connection_is_complete == false){
        painter.drawLine(start,end);
        return;
    }
    painter.drawLine((screen->shapeById(from_id))->getCenter(),(screen->shapeById(to_id))->getCenter());
}

void Connection::serialize(QDataStream& out)const{
    out<<from_id<<to_id<<start<<end<<connection_is_complete;
}

void Connection::deserialize(QDataStream& in){
    in>>from_id>>to_id>>start>>end>>connection_is_complete;
}

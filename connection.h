#pragma once
#include"IShape.h"
class Screen;
class Connection
{
public:
    Connection();
    void draw(QPainter &,Screen*) const;
    int getFromId()const{return from_id;}
    int getToId()const{return to_id;}
    void setStartPoint(QPoint p){start = p;}
    void setEndPoint(QPoint p){end = p;}
    void setFromId(int id){from_id = id;}
    void setToId(int id){to_id = id;}
private:
    int from_id;
    int to_id;
    QPoint start;
    QPoint end;
};



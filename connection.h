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
    void connectionIsComplete(bool val){connection_is_complete = val;}
private:
    int from_id;
    int to_id;
    QPoint start;
    QPoint end;
    bool connection_is_complete = false;
};



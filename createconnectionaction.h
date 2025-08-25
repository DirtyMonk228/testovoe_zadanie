#pragma once
#include"IAction.h"
#include"connection.h"
#include"screen.h"
class CreateConnectionAction:public IAction
{
public:
    CreateConnectionAction();
    void mousePressEvent(QMouseEvent*,Screen*) override ;
    void mouseMoveEvent(QMouseEvent*,Screen*) override;
    void mouseReleaseEvent(QMouseEvent*,Screen*) override;
    void keyPressEvent(QKeyEvent*,Screen*) override;
    bool getShapeWithPointInside(shared_ptr<IShape>&,const std::vector<shared_ptr<IShape>>&,QPoint)const;
    void resetState(Screen* screen);
private:
    std::shared_ptr<Connection> connect = std::make_shared<Connection>();
    bool first_click = true;
    bool connection_on_screen = false;
};



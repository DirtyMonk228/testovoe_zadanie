#pragma once
#include"IAction.h"
#include"IShape.h"
#include"screen.h"
#include"circle.h"
using std::shared_ptr;
class CreateCircleAction:public IAction
{
public:
    CreateCircleAction();
    void mousePressEvent(QMouseEvent*,Screen*) override;
    void mouseMoveEvent(QMouseEvent*,Screen*) override;
    void mouseReleaseEvent(QMouseEvent*,Screen*) override;
private:
    shared_ptr<Circle> circle;
    bool circle_already_on_screen = false;
};



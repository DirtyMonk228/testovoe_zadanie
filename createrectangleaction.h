#pragma once
#include"IAction.h"
#include"IShape.h"
#include"screen.h"
#include"rectangle.h"
using std::shared_ptr;
class CreateRectangleAction:public IAction
{
public:
    CreateRectangleAction();
    void mousePressEvent(QMouseEvent*,Screen*) override;
    void mouseMoveEvent(QMouseEvent*,Screen*) override;
    void mouseReleaseEvent(QMouseEvent*,Screen*) override;
private:
    shared_ptr<Rectangle> rectangle;
    bool rectangle_already_on_screen = false;
};



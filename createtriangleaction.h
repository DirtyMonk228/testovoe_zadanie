#pragma once
#include"IAction.h"
#include"IShape.h"
#include"triangle.h"
class CreateTriangleAction:public IAction
{
public:
    CreateTriangleAction();
    void mousePressEvent(QMouseEvent*,Screen*) override;
    void mouseMoveEvent(QMouseEvent*,Screen*) override;
    void mouseReleaseEvent(QMouseEvent*,Screen*) override;
private:
    Triangle* triangle = new Triangle();

};


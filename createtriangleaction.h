#pragma once
#include"IAction.h"
#include"IShape.h"
#include"screen.h"
#include"triangle.h"
using std::shared_ptr;
class CreateTriangleAction:public IAction
{
public:
    CreateTriangleAction();
    void mousePressEvent(QMouseEvent*,Screen*) override;
    void mouseMoveEvent(QMouseEvent*,Screen*) override;
    void mouseReleaseEvent(QMouseEvent*,Screen*) override;
    void keyPressEvent(QKeyEvent*, Screen*) override;
private:
    shared_ptr<Triangle> triangle;
    bool triangle_already_on_screen = false;
    bool draw_triangle = false;

};


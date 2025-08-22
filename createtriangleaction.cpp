#include "createtriangleaction.h"

CreateTriangleAction::CreateTriangleAction():IAction() {}

void CreateTriangleAction::mousePressEvent(QMouseEvent* me, Screen* screen){
    triangle = std::make_shared<Triangle>();
    triangle->setFirstPoint(me->position().toPoint());
    triangle_already_on_screen = false;
}
void CreateTriangleAction::mouseMoveEvent(QMouseEvent* me,Screen* screen){
    triangle->setSecondPoint(me->position().toPoint());
    if(false == triangle_already_on_screen){
        screen->addShape(triangle);
        triangle_already_on_screen = true;
    }
    screen->update();
}
void CreateTriangleAction::mouseReleaseEvent(QMouseEvent* me, Screen* screen){
    triangle->setSecondPoint(me->position().toPoint());

    screen->update();
}


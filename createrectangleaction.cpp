#include "createrectangleaction.h"

CreateRectangleAction::CreateRectangleAction():IAction() {}

void CreateRectangleAction::mousePressEvent(QMouseEvent* me, Screen* screen){
    rectangle = std::make_shared<Rectangle>();
    rectangle->setFirstPoint(me->position().toPoint());
    rectangle_already_on_screen = false;
}
void CreateRectangleAction::mouseMoveEvent(QMouseEvent* me,Screen* screen){
    rectangle->setSecondPoint(me->position().toPoint());
    if(false == rectangle_already_on_screen){
        screen->addShape(rectangle);
        rectangle_already_on_screen = true;
    }
    screen->update();
}
void CreateRectangleAction::mouseReleaseEvent(QMouseEvent* me, Screen* screen){
    rectangle->setSecondPoint(me->position().toPoint());

    screen->update();
}


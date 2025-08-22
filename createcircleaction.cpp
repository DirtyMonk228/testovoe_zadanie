#include "createcircleaction.h"

CreateCircleAction::CreateCircleAction():IAction() {}

void CreateCircleAction::mousePressEvent(QMouseEvent* me, Screen* screen){
    circle = std::make_shared<Circle>();
    circle->setFirstPoint(me->position().toPoint());
    circle_already_on_screen = false;
}
void CreateCircleAction::mouseMoveEvent(QMouseEvent* me,Screen* screen){
    circle->setSecondPoint(me->position().toPoint());
    if(false == circle_already_on_screen){
        screen->addShape(circle);
        circle_already_on_screen = true;
    }
    screen->update();
}
void CreateCircleAction::mouseReleaseEvent(QMouseEvent* me, Screen* screen){
    circle->setSecondPoint(me->position().toPoint());

    screen->update();
}


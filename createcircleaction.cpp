#include "createcircleaction.h"
#include"getFreeId.h"
CreateCircleAction::CreateCircleAction():IAction() {
    circle = std::make_shared<Circle>(get_free_id());
}

void CreateCircleAction::mousePressEvent(QMouseEvent* me, Screen* screen){
    if(me->button() == Qt::RightButton && circle_already_on_screen){
        screen->deleteShape(screen->countOfShapes()-1);
        screen->update();
        return;
    }
    if(me->button() == Qt::RightButton) return;
    circle->setFirstPoint(me->position().toPoint());
    draw_circle = true;
}
void CreateCircleAction::mouseMoveEvent(QMouseEvent* me,Screen* screen){
    if(!draw_circle) return;
    circle->setSecondPoint(me->position().toPoint());
    if(false == circle_already_on_screen){
        screen->addShape(circle);
        circle_already_on_screen = true;
    }
    screen->update();
}
void CreateCircleAction::mouseReleaseEvent(QMouseEvent* me, Screen* screen){
    circle->setSecondPoint(me->position().toPoint());
    circle = std::make_shared<Circle>(get_free_id());
    draw_circle = false;
    circle_already_on_screen = false;
    screen->update();
}
void CreateCircleAction::keyPressEvent(QKeyEvent* ke, Screen* screen){
    if(ke->key() == Qt::Key_Escape && circle_already_on_screen){
        screen->deleteShape(screen->countOfShapes()-1);
        draw_circle = false;
        circle_already_on_screen = false;
        screen->update();

    }
}

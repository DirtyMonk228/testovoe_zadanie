#include "createrectangleaction.h"
#include"getFreeId.h"
CreateRectangleAction::CreateRectangleAction():IAction() {
    rectangle = std::make_shared<Rectangle>(get_free_id());
}

void CreateRectangleAction::mousePressEvent(QMouseEvent* me, Screen* screen){
    if(me->button() == Qt::RightButton && rectangle_already_on_screen){
        screen->deleteShape(screen->countOfShapes()-1);
        screen->update();
    }
    rectangle->setFirstPoint(me->position().toPoint());
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
    rectangle = std::make_shared<Rectangle>(get_free_id());
    rectangle_already_on_screen = false;
    screen->update();
}

void CreateRectangleAction::keyPressEvent(QKeyEvent* ke, Screen* screen){
    if(ke->key() == Qt::Key_Escape && rectangle_already_on_screen){
        screen->deleteShape(screen->countOfShapes()-1);
        screen->update();
    }
}

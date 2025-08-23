#include "createtriangleaction.h"
#include"getFreeId.h"
CreateTriangleAction::CreateTriangleAction():IAction() {
    triangle = std::make_shared<Triangle>(get_free_id());
}

void CreateTriangleAction::mousePressEvent(QMouseEvent* me, Screen* screen){
    if(me->button() == Qt::RightButton && triangle_already_on_screen){
        screen->deleteShape(screen->countOfShapes()-1);
        screen->update();
    }
    triangle->setFirstPoint(me->position().toPoint());
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
    triangle = std::make_shared<Triangle>(get_free_id());
    triangle_already_on_screen = false;
    screen->update();
}

void CreateTriangleAction::keyPressEvent(QKeyEvent* ke, Screen* screen){
    if(ke->key() == Qt::Key_Escape && triangle_already_on_screen){
        screen->deleteShape(screen->countOfShapes()-1);
        screen->update();
    }
}

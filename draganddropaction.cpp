#include "draganddropaction.h"
#include"IShape.h"
#include"screen.h"
DragAndDropAction::DragAndDropAction():IAction() {}

bool DragAndDropAction::getShapeWithPointInside(std::shared_ptr<IShape>& for_save,const std::vector<std::shared_ptr<IShape>>& shapes,QPoint point){
    for(int i = 0;i<shapes.size();++i){
        if(shapes[i]->isPointInShape(point)){
            for_save = shapes[i];
            return true;
        }
    }
    return false;
}
void DragAndDropAction::mousePressEvent(QMouseEvent* me,Screen* screen){

    if(getShapeWithPointInside(drag_shape,screen->getShapes(),me->position().toPoint()) == true){
        screen->setCursor(QCursor(Qt::PointingHandCursor));
        start_drag = true;
        old_point = me->position().toPoint();
    }

}

void DragAndDropAction::mouseMoveEvent(QMouseEvent* me,Screen* screen){
    if(start_drag) {
        new_point = me->position().toPoint();
        drag_shape->moveShape(new_point - old_point);
        screen->update();
        old_point = new_point;
    }

}

void DragAndDropAction::mouseReleaseEvent(QMouseEvent* me,Screen* screen){
    screen->setCursor(Qt::ArrowCursor);
    start_drag = false;
}
void DragAndDropAction::keyPressEvent(QKeyEvent* ke,Screen* screen){

}

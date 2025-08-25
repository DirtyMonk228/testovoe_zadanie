#include "draganddropaction.h"
#include"IShape.h"
#include"screen.h"
DragAndDropAction::DragAndDropAction():IAction() {}

bool DragAndDropAction::getShapeWithPointInside(std::shared_ptr<IShape>& for_save,const std::vector<std::shared_ptr<IShape>>& shapes,QPoint point) const{
    double min_area = INT64_MAX;
    bool success = false;
    for(int i = 0;i<shapes.size();++i){
        double current_area = shapes[i]->getArea();
        if(shapes[i]->isPointInShape(point) && current_area<min_area){
            success = true;
            for_save = shapes[i];
            min_area = current_area;

        }
    }
    return success;
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

#include "deleteshapeaction.h"
#include"screen.h"
DeleteShapeAction::DeleteShapeAction():IAction() {}


bool DeleteShapeAction::getShapeWithPointInside(std::shared_ptr<IShape>& for_save,const std::vector<std::shared_ptr<IShape>>& shapes,QPoint point) const{
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
void DeleteShapeAction::mousePressEvent(QMouseEvent* me,Screen* screen){
    if(getShapeWithPointInside(shape,screen->getShapes(),me->position().toPoint())){
        screen->deleteShapeById(shape->getId());
        screen->deleteConnectionWithShapeId(shape->getId());
        screen->update();
    }
}


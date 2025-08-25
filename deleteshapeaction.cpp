#include "deleteshapeaction.h"
#include"screen.h"
DeleteShapeAction::DeleteShapeAction():IAction() {}


bool DeleteShapeAction::getShapeWithPointInside(std::shared_ptr<IShape>& for_save,const std::vector<std::shared_ptr<IShape>>& shapes,QPoint point){
    for(int i = 0;i<shapes.size();++i){
        if(shapes[i]->isPointInShape(point)){
            for_save = shapes[i];
            return true;
        }
    }
    return false;
}
void DeleteShapeAction::mousePressEvent(QMouseEvent* me,Screen* screen){
    if(getShapeWithPointInside(shape,screen->getShapes(),me->position().toPoint())){
        screen->deleteShapeById(shape->getId());
        screen->deleteConnectionWithShapeId(shape->getId());
        screen->update();
    }
}


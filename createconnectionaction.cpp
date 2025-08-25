#include "createconnectionaction.h"
#include"IShape.h"
CreateConnectionAction::CreateConnectionAction():IAction() {}


void CreateConnectionAction::resetState(Screen* screen){
    first_click = true;
    screen->setMouseTracking(false);
    connect = std::make_shared<Connection>();
    connection_on_screen = false;
}
bool CreateConnectionAction::getShapeWithPointInside(std::shared_ptr<IShape>& for_save,const std::vector<std::shared_ptr<IShape>>& shapes,QPoint point){
    for(int i = 0;i<shapes.size();++i){
        if(shapes[i]->isPointInShape(point)){
            for_save = shapes[i];
            return true;
        }
    }
    return false;
}
void CreateConnectionAction::mousePressEvent(QMouseEvent* me, Screen* screen){
    std::shared_ptr<IShape> tmp;
    if(me->button() == Qt::RightButton && connection_on_screen){
        screen->deleteConnection(screen->countOfConnection()-1);
        resetState(screen);
        screen->update();
    }
    if(first_click == false && !getShapeWithPointInside(tmp,screen->getShapes(),me->position().toPoint())){
        screen->deleteConnection(screen->countOfConnection()-1);
        resetState(screen);
        screen->update();

        return;
    }
    if(!getShapeWithPointInside(tmp,screen->getShapes(),me->position().toPoint()))return;
    if(first_click){
        connect->setStartPoint(tmp->getCenter());
        connect->setFromId(tmp->getId());
        screen->setMouseTracking(true);
        first_click = false;
    }
    else{
        connect->setEndPoint(tmp->getCenter());
        connect->setToId(tmp->getId());
        connect->connectionIsComplete(true);
        if(connect->getFromId() == connect->getToId())screen->deleteConnection(screen->countOfConnection()-1);
        resetState(screen);
        screen->update();

    }
}

void CreateConnectionAction::mouseMoveEvent(QMouseEvent* me,Screen* screen){
    if(first_click == true)return;
    connect->setEndPoint(me->position().toPoint());

    if(!connection_on_screen){
        connection_on_screen = true;
        screen->addConnection(connect);
    }
    screen->update();


}
void CreateConnectionAction::keyPressEvent(QKeyEvent* ke,Screen* screen){
    if(ke->key() == Qt::Key_Escape && connection_on_screen){
        screen->deleteConnection(screen->countOfConnection()-1);
        resetState(screen);
        screen->update();
    }
}

void CreateConnectionAction::mouseReleaseEvent(QMouseEvent* me,Screen* screen){

}

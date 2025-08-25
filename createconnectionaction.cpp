#include "createconnectionaction.h"
#include"IShape.h"
CreateConnectionAction::CreateConnectionAction():IAction() {}


void CreateConnectionAction::resetState(Screen* screen){
    first_click = true;
    screen->setMouseTracking(false);
    connect = std::make_shared<Connection>();
    connection_on_screen = false;
}
bool CreateConnectionAction::getShapeWithPointInside(std::shared_ptr<IShape>& for_save,const std::vector<std::shared_ptr<IShape>>& shapes,QPoint point)const{
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
void CreateConnectionAction::mousePressEvent(QMouseEvent* me, Screen* screen){
    std::shared_ptr<IShape> tmp;
    if(me->button() == Qt::RightButton && connection_on_screen){//отмена отрисовки по нажатию пкм
        screen->deleteConnection(screen->countOfConnection()-1);
        resetState(screen);
        screen->update();
        return;
    }
    if(me->button() == Qt::RightButton)return;//не дает рисовать нажатием пкм
    if(first_click == false && !getShapeWithPointInside(tmp,screen->getShapes(),me->position().toPoint())){//удаление связи в случае неуспешного коннекта
        screen->deleteConnection(screen->countOfConnection()-1);
        resetState(screen);
        screen->update();

        return;
    }
    if(!getShapeWithPointInside(tmp,screen->getShapes(),me->position().toPoint()))return;//отсутствие создания связи при не попадании по фигуре
    if(first_click){//начало генерации связи в случае успешного первого клика по фигуре
        connect->setStartPoint(tmp->getCenter());
        connect->setFromId(tmp->getId());
        screen->setMouseTracking(true);
        first_click = false;
    }
    else{//создание связи меж фигурами
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

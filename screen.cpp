#include "screen.h"

Screen::Screen(QWidget *parent)
    : QWidget{parent}
{
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    resize(size_screen);
    current_action = new CreateCircleAction;
}

void Screen::addShape(const shared_ptr<IShape>& shape){
    shapes.push_back(shape);
}

void Screen::deleteShape(int position){
    shapes.erase(shapes.begin()+position);
}

auto Screen::shapeById(int id){
    auto it = std::find_if(shapes.begin(),shapes.end(),
                           [id](const shared_ptr<IShape>& shape){return shape->getId() == id;});
    return it;
}

void Screen::deleteConnection(int id){
    connections.erase(
        std::remove_if(connections.begin(), connections.end(),
                       [id](const Connection& conn) {
                           return conn.getFromId() == id|| conn.getToId() == id;
                       }),
        connections.end());
}

void Screen::addConnection(Connection conn){
    connections.push_back(conn);
}
// void Screen::deleteShape(const shared_ptr<IShape>& shape){

// }
int Screen::countOfShapes() const{return shapes.size();}


void Screen::setAction(IAction* act){
    if(current_action) delete current_action;
    current_action = act;
}

void Screen::paintEvent(QPaintEvent* pe){
    QPainter painter(this);
    painter.fillRect(0,0,width(),height(),background_color);
    painter.setPen(QPen(Qt::black,3));
    for(int i = 0;i<shapes.size();++i) shapes[i]->draw(painter);
}
void Screen::mousePressEvent(QMouseEvent* me){
    current_action->mousePressEvent(me,this);
}
void Screen::mouseMoveEvent(QMouseEvent* me){
    current_action->mouseMoveEvent(me,this);
}

void Screen::mouseReleaseEvent(QMouseEvent* me){
    current_action->mouseReleaseEvent(me,this);
}

void Screen::keyPressEvent(QKeyEvent* ke){
    current_action->keyPressEvent(ke,this);
}
Screen::~Screen(){
    delete current_action;
}

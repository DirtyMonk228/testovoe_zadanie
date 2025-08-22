#include "screen.h"

Screen::Screen(QWidget *parent)
    : QWidget{parent}
{
    resize(size_screen);
    current_action = new CreateCircleAction;
}

void Screen::addShape(const shared_ptr<IShape>& shape){
    shapes.push_back(shape);
}

void Screen::deleteShape(int position){
    shapes.erase(shapes.begin()+position,shapes.begin()+position+1);
}

int Screen::countOfShapes(){return shapes.size();}


void Screen::setAction(IAction* act){
    if(current_action) delete current_action;
    current_action = act;
}

void Screen::paintEvent(QPaintEvent* pe){
    QPainter painter(this);
    painter.fillRect(0,0,size_screen.width(),size_screen.height(),background_color);
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

Screen::~Screen(){
    delete current_action;
}

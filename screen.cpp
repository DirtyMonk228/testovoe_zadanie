#include "screen.h"

Screen::Screen(QWidget *parent)
    : QWidget{parent}
{
    resize(size_screen);
}

void Screen::addShape(IShape* shape){
    shapes.push_back(shape);
}

void Screen::changeShape(IShape* shape,int position){
    delete shapes[position];
    shapes[position] = shape;
}

void Screen::deleteShape(int position){
    shapes.erase(shapes.begin()+position,shapes.begin()+position+1);
}

void Screen::setAction(IAction* act){
    if(current_action) delete current_action;
    current_action = act;
}

void Screen::paintEvent(QPaintEvent* pe){
    QPainter painter(this);
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

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

void Screen::deleteShapeById(int id){
    shapes.erase(std::find_if(shapes.begin(),shapes.end(),
                              [id](const std::shared_ptr<IShape>& shape){return shape->getId() == id;}));
}

shared_ptr<IShape> Screen::shapeById(int id){
    auto it = std::find_if(shapes.begin(),shapes.end(),
                           [id](const shared_ptr<IShape>& shape){return shape->getId() == id;});
    return *it;
}

void Screen::deleteConnectionWithShapeId(int id){
    connections.erase(
        std::remove_if(connections.begin(), connections.end(),
                       [id](const shared_ptr<Connection>&  conn) {
                           return conn->getFromId() == id|| conn->getToId() == id;
                       }),
        connections.end());
}

void Screen::addConnection(std::shared_ptr<Connection> conn){
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
    for(int i = 0;i<connections.size();++i) connections[i]->draw(painter,this);
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

void Screen::serialize(QString filename) const{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_6_0);
    int shapes_size = shapes.size();
    out<<shapes_size;
    for(int i = 0;i<shapes.size();++i) shapes[i]->serialize(out);
    int connections_size = connections.size();
    out<<connections_size;
    for(int i = 0;i<connections.size();++i)connections[i]->serialize(out);
    file.close();
}

void Screen::deserialize(QString filename,std::unique_ptr<IShape> (*create_shape)(QString)){
    shapes.clear();
    connections.clear();
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_6_0);
    int count_shapes;
    in>>count_shapes;
    for(int i = 0;i<count_shapes;++i){
        QString type;
        in>>type;
        shapes.push_back(create_shape(type));
        shapes[i]->deserialize(in);
    }
    int count_connections;
    in>>count_connections;
    for(int i = 0;i<count_connections;++i){
        connections.push_back(std::make_shared<Connection>());
        connections[i]->deserialize(in);
    }

    file.close();
    update();


}
Screen::~Screen(){
    delete current_action;
}

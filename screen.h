#pragma once
#include <QWidget>
#include<vector>
#include"IShape.h"
#include"IAction.h"
#include"createtriangleaction.h"
#include"createrectangleaction.h"
#include"createcircleaction.h"
#include"connection.h"
using std::shared_ptr;
class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = nullptr);
    void addShape(const shared_ptr<IShape> &);
    void deleteShape(int);
    void deleteShapeById(int id);
    const std::vector<shared_ptr<IShape>>& getShapes(){return shapes;}
    shared_ptr<IShape> shapeById(int id);
    void deleteConnectionWithShapeId(int id);
    void deleteConnection(int position){connections.erase(connections.begin()+position);}
    void addConnection(std::shared_ptr<Connection>);
    int countOfShapes()const;
    int countOfConnection(){return connections.size();}
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*)override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void keyPressEvent(QKeyEvent* ) override;
    void setAction(IAction*);
    ~Screen();

private:
    QSize size_screen = QSize(500,500);
    std::vector<shared_ptr<IShape>> shapes;
    std::vector<shared_ptr<Connection>> connections;
    IAction* current_action;
    QColor background_color = QColor(255,255,255);

};



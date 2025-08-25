#pragma once
#include <QWidget>
#include<vector>
#include"IShape.h"
#include"IAction.h"
#include"createtriangleaction.h"
#include"createrectangleaction.h"
#include"create_shapes_by_type.h"
#include"createcircleaction.h"
#include"connection.h"
#include<QFile>
using std::shared_ptr;
class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = nullptr);
    void addShape(const shared_ptr<IShape> &);
    void deleteShape(int pos);
    void deleteShapeById(int id);
    int countOfShapes()const;
    const std::vector<shared_ptr<IShape>>& getShapes(){return shapes;}
    shared_ptr<IShape> shapeById(int id);

    void deleteConnectionWithShapeId(int id);
    void deleteConnection(int position){connections.erase(connections.begin()+position);}
    void addConnection(std::shared_ptr<Connection>);
    int countOfConnection(){return connections.size();}

    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*)override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void keyPressEvent(QKeyEvent* ) override;

    void setAction(IAction*);

    void serialize(QString filename)const;
    void deserialize(QString filename, std::unique_ptr<IShape> (*create_shape)(QString) = create_shapes_by_type);
    ~Screen();

private:
    QSize size_screen = QSize(500,500);
    std::vector<shared_ptr<IShape>> shapes;
    std::vector<shared_ptr<Connection>> connections;
    IAction* current_action;
    QColor background_color = QColor(255,255,255);

};



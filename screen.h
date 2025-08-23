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
    auto shapeById(int id);
    void deleteConnection(int id);
    void addConnection(Connection);
    int countOfShapes()const;
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*)override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void keyPressEvent(QKeyEvent* ) override;
    ~Screen();

private:
    QSize size_screen = QSize(500,500);
    std::vector<shared_ptr<IShape>> shapes;
    std::vector<Connection> connections;
    IAction* current_action;
    QColor background_color = QColor(255,255,255);
public slots:
    void setAction(IAction*);
};



#pragma once
#include <QWidget>
#include<vector>
#include"IShape.h"
#include"IAction.h"
#include"createtriangleaction.h"
#include"createrectangleaction.h"
#include"createcircleaction.h"
using std::shared_ptr;
class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = nullptr);
    void addShape(const shared_ptr<IShape> &);
    void deleteShape(int);
    int countOfShapes();
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*)override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    ~Screen();

private:
    QSize size_screen = QSize(500,500);
    std::vector<shared_ptr<IShape>> shapes;
    IAction* current_action;
    QColor background_color = QColor(255,255,255);
public slots:
    void setAction(IAction*);
};



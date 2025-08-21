#pragma once
#include <QWidget>
#include<vector>
#include"IShape.h"
#include"IAction.h"
class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = nullptr);
    void addShape(IShape*);
    void changeShape(IShape*,int);
    void deleteShape(int);
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*)override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
private:
    QSize size_screen = QSize(500,500);
    std::vector<IShape*> shapes;
    IAction* current_action = nullptr;
public slots:
    void setAction(IAction*);
};



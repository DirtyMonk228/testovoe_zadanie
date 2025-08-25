#pragma once
#include"IShape.h"
#include"IAction.h"
class DeleteShapeAction:public IAction
{
public:
    DeleteShapeAction();
    void mousePressEvent(QMouseEvent*, Screen*screen) override;
    void mouseMoveEvent(QMouseEvent*,Screen*) override{}
    void mouseReleaseEvent(QMouseEvent*,Screen*) override{}
    void keyPressEvent(QKeyEvent*,Screen*) override{}
    bool getShapeWithPointInside(std::shared_ptr<IShape>&,const std::vector<std::shared_ptr<IShape>>&,QPoint);
private:
    std::shared_ptr<IShape> shape;

};


#pragma once
#include"IAction.h"
#include"IShape.h"
class DragAndDropAction:public IAction
{
public:
    DragAndDropAction();
    void mousePressEvent(QMouseEvent*,Screen*) override;
    void mouseMoveEvent(QMouseEvent*,Screen*) override;
    void mouseReleaseEvent(QMouseEvent*,Screen*) override;
    void keyPressEvent(QKeyEvent*,Screen*) override;
    bool getShapeWithPointInside(std::shared_ptr<IShape>&,const std::vector<std::shared_ptr<IShape>>&,QPoint)const;
private:
    bool start_drag = false;
    std::shared_ptr<IShape> drag_shape;
    QPoint old_point;
    QPoint new_point;
};


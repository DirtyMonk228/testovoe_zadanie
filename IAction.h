#pragma once
#include<QPoint>
#include<QMouseEvent>
//#include"screen.h"
class Screen;
class IAction{
public:
    virtual void mousePressEvent(QMouseEvent*,Screen*) = 0;
    virtual void mouseMoveEvent(QMouseEvent*,Screen*) = 0;
    virtual void mouseReleaseEvent(QMouseEvent*,Screen*) = 0;
    virtual ~IAction() = default;
};

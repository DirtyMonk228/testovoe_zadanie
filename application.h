#pragma once
#include<QBoxLayout>
#include<QPushButton>
#include <QWidget>
#include"screen.h"
class Application : public QWidget
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();
private:
    std::array<QPushButton*,8> buttons;
    QSize icon_size = QSize(30,30);
    Screen* screen = new Screen;
public slots:
    void buttonMode();
};


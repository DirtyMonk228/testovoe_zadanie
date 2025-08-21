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

    QPushButton* triangle_btn = new QPushButton;
    QPushButton* square_btn = new QPushButton;
    QPushButton* circle_btn = new QPushButton;
    QPushButton* stick_btn = new QPushButton;
    QPushButton* hand_btn = new QPushButton;
    QPushButton* trash_btn = new QPushButton;
    QPushButton* save_btn = new QPushButton;
    QPushButton* folder_btn = new QPushButton;
    QSize icon_size = QSize(30,30);
    Screen* screen = new Screen;
};


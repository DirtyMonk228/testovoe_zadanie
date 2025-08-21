#include "application.h"

Application::Application(QWidget *parent)
    : QWidget(parent)
{
    triangle_btn->setIcon(QIcon("/home/ss/cppProjects/test_paint_job/images/triangle.png"));
    square_btn->setIcon(QIcon("/home/ss/cppProjects/test_paint_job/images/square.png"));
    circle_btn->setIcon(QIcon("/home/ss/cppProjects/test_paint_job/images/circle.png"));
    stick_btn->setIcon(QIcon("/home/ss/cppProjects/test_paint_job/images/stick.png"));
    hand_btn->setIcon(QIcon("/home/ss/cppProjects/test_paint_job/images/hand.png"));
    trash_btn->setIcon(QIcon("/home/ss/cppProjects/test_paint_job/images/trash.png"));
    save_btn->setIcon(QIcon("/home/ss/cppProjects/test_paint_job/images/save.png"));
    folder_btn->setIcon(QIcon("/home/ss/cppProjects/test_paint_job/images/folder.png"));



    triangle_btn->setIconSize(icon_size);
    square_btn->setIconSize(icon_size);
    circle_btn->setIconSize(icon_size);
    stick_btn->setIconSize(icon_size);
    hand_btn->setIconSize(icon_size);
    trash_btn->setIconSize(icon_size);
    save_btn->setIconSize(icon_size);
    folder_btn->setIconSize(icon_size);

    QHBoxLayout* menu_layout = new QHBoxLayout;
    menu_layout->addWidget(triangle_btn);
    menu_layout->addWidget(square_btn);
    menu_layout->addWidget(circle_btn);
    menu_layout->addWidget(stick_btn);
    menu_layout->addWidget(hand_btn);
    menu_layout->addWidget(trash_btn);
    menu_layout->addWidget(save_btn);
    menu_layout->addWidget(folder_btn);
    QVBoxLayout* menu_with_screen_layout = new QVBoxLayout;
    menu_with_screen_layout->addLayout(menu_layout);
    menu_with_screen_layout->addWidget(screen);
    setLayout(menu_with_screen_layout);
    resize(screen->width(),screen->height()+icon_size.height());
}

Application::~Application() {}

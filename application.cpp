#include "application.h"
#include"createconnectionaction.h"
#include"createtriangleaction.h"
#include"draganddropaction.h"
#include"deleteshapeaction.h"
Application::Application(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* menu_layout = new QHBoxLayout;
    std::array<QString,8> names{"triangle","rectangle","circle","connection","hand","trash","save","load"};
    for(int i = 0;i<buttons.size();++i){
        buttons[i] = new QPushButton;
        QString image_path = QString("../../images/%1.png").arg(i + 1);
        buttons[i]->setIcon(QIcon(image_path));
        buttons[i]->setIconSize(icon_size);
        buttons[i]->setObjectName(names[i]);
        connect(buttons[i],SIGNAL(clicked()),this,SLOT(buttonMode()));
        menu_layout->addWidget(buttons[i]);
    }
    QVBoxLayout* menu_with_screen_layout = new QVBoxLayout;
    menu_with_screen_layout->addLayout(menu_layout);
    menu_with_screen_layout->addWidget(screen);
    setLayout(menu_with_screen_layout);
    resize(screen->width(),screen->height()+icon_size.height());
}

void Application::buttonMode(){
    QString button_name = sender()->objectName();
    IAction* action;
    if(button_name == "triangle") action = new CreateTriangleAction;
    else if(button_name == "rectangle") action = new CreateRectangleAction;
    else if(button_name == "circle") action = new CreateCircleAction;
    else if(button_name == "hand")action = new DragAndDropAction;
    else if(button_name == "connection") action = new CreateConnectionAction;
    else if(button_name == "trash") action = new DeleteShapeAction;
    screen->setAction(action);
}

Application::~Application() {}

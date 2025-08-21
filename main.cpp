#include "application.h"
#include<QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //app.setStyle(QStyleFactory::create("Windows"));
    Application w;
    w.show();
    return app.exec();
}

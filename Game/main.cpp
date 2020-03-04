#include "core/mapwindow.hh"
#include "core/menuwindow.h"

#include <QApplication>


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);



    MenuWindow menuwindow;
    menuwindow.show();


    return app.exec();
}

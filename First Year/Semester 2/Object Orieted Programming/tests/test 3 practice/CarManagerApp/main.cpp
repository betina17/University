#include "CarManagerApp.h"
#include <QtWidgets/QApplication>
#include "Service.h"

int main(int argc, char *argv[])
{   
   
    QApplication a(argc, argv);
    CarManagerApp app;
    app.show();
    return a.exec();
    
}

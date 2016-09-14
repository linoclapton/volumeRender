//#include "MyWindow.h"
#include "Present.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <fstream>
#include <QPushButton>
#include "Utility.h"
int main(int argc, char *argv[])
{
    Utility::Clock clock;
    clock.start();
    QApplication a(argc, argv);
    Present* myWindow = new Present;
    myWindow->show();
    myWindow->readin();
    myWindow->_applyTFButton->click();
    clock.end("total");
    return a.exec();
}


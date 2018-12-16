#include "mainwindow.h"
#include <QApplication>

//TODO
//    Fix fast switching video record
//    Add filters

#include <Windows.h>
#include <iostream>
#include <opencv2/core.hpp>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    ImageController b;
//    ImageControllerEditor c(&b);
//    c.show();


    return a.exec();
}

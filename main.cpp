#include "mainwindow.h"
#include <QApplication>

//TODO
//    Fix fast switching video record
//    Add filters

#include <Windows.h>
#include <iostream>
#include <opencv2/core.hpp>

#include "Filters/imagecontrollereditor.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    ImageControllerEditor w;
    w.show();
    return a.exec();
}

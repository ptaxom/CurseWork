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
    double t = (double)cv::getTickCount(), t2;
    Sleep(400);
    t2 = (double)cv::getTickCount();
    std::cout << (t2 - t)/(cv::getTickFrequency());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>

//TODO
//    Fix fast switching video record
//    Add filters
//    Пропорциональный детектор
//    Фильтр обведенка

//Иконки и фикс багов

#include <QDebug>

#include <opencv2/core.hpp>

#include "Filters/ColorSpaceFilters/ColorFilterEditor/colorfiltereditor.h"
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    std::vector<QString> aa = {"13"};

    ColorFilterEditor fff(nullptr,aa);
    fff.show();

    return a.exec();
}

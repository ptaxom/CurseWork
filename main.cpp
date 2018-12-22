#include "mainwindow.h"
#include <QApplication>

//TODO
//    Fix fast switching video record
//    Add filters
//    Пропорциональный детектор
//    Фильтр обведенка

//Иконки и фикс багов

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

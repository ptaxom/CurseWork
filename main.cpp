#include "mainwindow.h"
#include <QApplication>

//TODO
//    Фильтр обведенка

//Иконки и фикс багов

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

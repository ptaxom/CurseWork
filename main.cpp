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

#include "Filters/MorphFilters/MorphFilterEditor/morphfilterform.h"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

        AbstractFilter *f = nullptr;
        std::vector<QString> nn = {"123", "432"};
        MorphFilterForm form(f,nn);
        form.show();

//    ImageController b;
//    ImageControllerEditor c(&b);
//    c.show();


    return a.exec();
}

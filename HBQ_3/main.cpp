#include "widget.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.show();

    return a.exec();
}

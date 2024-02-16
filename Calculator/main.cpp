#include "ChertCalc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChertCalc w;
    w.show();
    return a.exec();
}

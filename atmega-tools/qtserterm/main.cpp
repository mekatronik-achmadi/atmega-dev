#include <QApplication>
#include "qtserterm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    qtserterm w;
    w.show();

    return a.exec();
}


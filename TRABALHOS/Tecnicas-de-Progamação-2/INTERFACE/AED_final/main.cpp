#include "TelaPrincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TelaPrincipal w;
    w.show();

    return a.exec();
}

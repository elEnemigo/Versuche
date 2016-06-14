#include "streetplanner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StreetPlanner w;
    w.show();

    return a.exec();
}

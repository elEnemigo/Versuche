#include "streetplanner.h"
#include <QApplication>

/**
 * @brief Entrypoint
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StreetPlanner w;
    w.show();

    return a.exec();
}

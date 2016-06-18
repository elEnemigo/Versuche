#include "city.h"

City::City(QString CityName, int XCoord, int YCoord)
    : Name(CityName), X(XCoord), Y(YCoord)
{

}

void City::draw(QGraphicsScene& scene)
{
    // Print debug string
    qDebug() << QString("Drawing City at X: %1 & Y: %2").arg(X).arg(Y);

    // Draw text and then city in red
    QGraphicsTextItem* cityName = scene.addText(Name);
    cityName->setPos(X + CITYSIZE/2, Y + CITYSIZE/2);
    scene.addEllipse(X, Y, CITYSIZE, CITYSIZE, QPen(), QBrush(Qt::red));
}

QString City::getName()
{
    return Name;
}

int City::getX()
{
    return X;
}

int City::getY()
{
    return Y;
}

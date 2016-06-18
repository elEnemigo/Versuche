#ifndef CITY_H
#define CITY_H

#include <string>
#include <QtDebug>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsTextItem>

#define CITYSIZE 10

class City
{
private:
    QString Name;
    int X, Y;
public:
    City(QString CityName, int XCoord, int YCoord);

    void draw(QGraphicsScene& scene);
    QString getName();
    int getX();
    int getY();
};

#endif // CITY_H

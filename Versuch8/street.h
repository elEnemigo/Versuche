#ifndef STREET_H
#define STREET_H

#include "city.h"

#include <QGraphicsScene>

class Street
{
private:
    City* A;
    City* B;
public:
    Street(City* FirstCity, City* SecondCity);

    City* getA() const;
    City* getB() const;
    void draw(QGraphicsScene& scene);
};

#endif // STREET_H

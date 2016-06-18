#ifndef MAP_H
#define MAP_H

#include "city.h"
#include "abstractmap.h"

#include <vector>

class Map : public AbstractMap
{
private:
    std::vector<City*> CityList;
    std::vector<Street*> StreetList;
public:
    Map();

    void addCity(City* NewCity);
    bool addStreet(Street* NewStreet);
    City* find_city(const QString city_name) const;
    void draw(QGraphicsScene &scene);
};

#endif // MAP_H

#ifndef MAP_H
#define MAP_H

//#include "city.h"
//#include "street.h"
#include "abstractmap.h"

#include <vector>

class Map : public AbstractMap
{
private:
    CityList Cities;
    StreetList Streets;
public:
    Map();

    void addCity(City* NewCity);
    bool addStreet(Street* NewStreet);
    City* find_city(const QString city_name) const;
    StreetList get_street_list(const City* city) const;
    City * get_opposite_city(const Street* street, const City* city) const;
    double get_length(const Street* street) const;
    void draw(QGraphicsScene &scene);
};

#endif // MAP_H

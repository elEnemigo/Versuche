#ifndef MAP_H
#define MAP_H

//#include "city.h"
//#include "street.h"
#include "abstractmap.h"

#include <vector>

class Map : public AbstractMap
{
private:
    CityList Cities;        //! List of cities
    StreetList Streets;     //! List of streets
public:
    /**
     * @brief Constructor. Dundo Nuffin
     */
    Map();

    bool addCity(City* NewCity);
    bool addStreet(Street* NewStreet);
    City* find_city(const QString city_name) const;
    StreetList get_street_list(const City* city) const;
    City * get_opposite_city(const Street* street, const City* city) const;
    double get_length(const Street* street) const;

    void draw(QGraphicsScene &scene) const;

    /**
     * @return  Returns a list of all cities in this map as @ref CityList
     */
    CityList get_city_list() const;
};

#endif // MAP_H

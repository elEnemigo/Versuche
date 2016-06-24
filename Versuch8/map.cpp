#include "abstractmap.h"
#include "map.h"

Map::Map()
{

}

void Map::addCity(City* NewCity)
{
    Cities.push_back(NewCity);
    qDebug() << NewCity->getName();
}

bool Map::addStreet(Street* NewStreet)
{
    if (find_city(NewStreet->getA()->getName()) && find_city(NewStreet->getB()->getName()))
    {
        Streets.push_back(NewStreet);
        return true;
    }

    return false;
}

City* Map::find_city(const QString city_name) const
{
    for (City* i: Cities)
        if (i->getName() == city_name)
            return i;
    return nullptr;
}

Map::StreetList Map::get_street_list(const City* city) const
{
    Map::StreetList retList;

    for (Street* i: Streets)
        if (i->getA() == city || i->getB() == city)
            retList.push_back(i);

    return retList;
}

City * Map::get_opposite_city(const Street* street, const City* city) const
{
    if (street->getA() == city)
        return street->getB();
    else if (street->getB() == city)
        return street->getA();
    else
        return nullptr;
}


double Map::get_length(const Street* street) const
{
    double xDff = abs(street->getA()->getX() - street->getB()->getX());
    double yDff = abs(street->getA()->getY() - street->getB()->getY());
    return sqrt(xDff*xDff + yDff*yDff);
}

void Map::draw(QGraphicsScene &scene)
{
    scene.clear();

    for (City* i: Cities)
        i->draw(scene);

    for (Street* i: Streets)
        i->draw(scene);
}

Map::CityList Map::get_city_list() const
{
    return Cities;
}

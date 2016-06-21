#include "map.h"

Map::Map()
{

}

void Map::addCity(City* NewCity)
{
    CityList.push_back(NewCity);
    qDebug() << NewCity->getName();
}

bool Map::addStreet(Street* NewStreet)
{
    if (find_city(NewStreet->getA()->getName()) && find_city(NewStreet->getB()->getName()))
        return true;

    return false;
}

City* Map::find_city(const QString city_name) const
{
    for (City* i: CityList)
        if (i->getName() == city_name)
            return i;
    return nullptr;
}

void Map::draw(QGraphicsScene &scene)
{
    scene.clear();

    for (City* i: CityList)
        i->draw(scene);
}

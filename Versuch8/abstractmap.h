#ifndef ABSTRACTMAP_H
#define ABSTRACTMAP_H

#include "city.h"
#include "street.h"

/**
 * @brief AbstractMap class. Abstract class
 */
class AbstractMap {
public:
	typedef std::vector<City *> CityList;
	typedef std::vector<Street *> StreetList;

    /**
    * @brief Add city to map
    *
    *  Adds the provided city to this map. If a city with the same name has
    *  been added before, the city is not added.
    *
    * @param City Pointer to @ref City to add
    * @return Return true if the city has beed added.
    */
    virtual bool addCity(City *) = 0;

    /**
     * @brief Add street to map
     *
     *  Adds the provided street to this map. If the cities linked by the street
	 *  have not been added to this map before, the street is not added.
	 *
     * @param Street  Pointer to @ref Street to add
     * @return Return true if the street has beed added.
	 */
    virtual bool addStreet(Street *) = 0;

	/**
	 * @brief Search for a city in this map by given name.
	 * @param city_name  Name to search
	 * @return the city pointer, if city not found NULL
	 */
    virtual City* find_city(const QString city_name) const = 0;

	/**
	 * @brief Search for streets in this map.
	 * @param city where you want the street_list from
	 * @return a list of all streets in this map connected to provided city.
	 */
    virtual StreetList get_street_list(const City* city) const = 0;

	/**
	 * @brief Look for opposite city.
	 * @param street
	 * @param city
	 * @return opposite city of the street. If city has no connection to street returns NULL.
	 */
    virtual City * get_opposite_city(const Street* street, const City* city) const = 0;

	/**
	 * @brief Calculate the street length.
	 * @param street
	 * @return length of the street
	 */
    virtual double get_length(const Street* street) const = 0;

    /**
     * @brief Draw the map.
     * @param scene  Scene to draw to
     */
    virtual void draw(QGraphicsScene &scene) const = 0;
};

#endif // ABSTRACTMAP_H


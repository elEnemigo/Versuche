#ifndef CITY_H
#define CITY_H

#include <string>
#include <QtDebug>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsTextItem>

#define CITYSIZE 10 // Draw size for city

/**
 * @brief City class.
 */
class City
{
private:
    QString Name;   //! String containing name of this city
    int X, Y;       //! Coordinates of the city
public:
    /**
     * @brief Constructor. Initializes variables
     * @param CityName  Name of the city
     * @param XCoord  X-Coordinate of city
     * @param YCoord  Y-Coordinate of city
     */
    City(QString CityName, int XCoord, int YCoord);

    /**
     * @brief Draw the city.
     * @param scene  Scene to draw to
     */
    void draw(QGraphicsScene& scene);

    /**
     * @return  Return city name as string
     */
    QString getName();

    /**
     * @return Returns X-Coordinate of city as integer
     */
    int getX();

    /**
     * @return Returns Y-Coordinate of city as integer
     */
    int getY();
};

#endif // CITY_H

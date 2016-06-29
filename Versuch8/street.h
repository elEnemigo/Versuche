#ifndef STREET_H
#define STREET_H

#include "city.h"

#include <QGraphicsScene>

/**
 * @brief Street class
 */
class Street
{
private:
    City* A;    //! First city
    City* B;    //! Second city
public:
    /**
     * @brief Constructor. Initializes connecting cities
     */
    Street(City* FirstCity, City* SecondCity);

    /**
     * @return Returns first city
     */
    City* getA() const;

    /**
     * @return Returns second city
     */
    City* getB() const;

    /**
     * @brief Draw the street.
     * @param scene  Scene to draw to
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Same as @ref draw. However draws a thick red line
     */
    void drawRed(QGraphicsScene& scene);
};

#endif // STREET_H

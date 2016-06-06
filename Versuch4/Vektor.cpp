//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einführung in die Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <iostream>

/**
 * @brief Constructor. Initializes x, y and z.
 *
 * @param inX  X-Value
 * @param inY  Y-Value
 * @param inZ  Z-Value
 */
Vektor::Vektor(double inX, double inY, double inZ)
{
	x = inX;
	y = inY;
	z = inZ;
}

/**
 * @brief Destructor
 */
Vektor::~Vektor()
{

}

/**
 * @brief Prints this vector into standard output.
 */
void Vektor::ausgabe() const
{
    //std::cout << "X: " << this->x << " | Y: " << this->y << " | Z: " << this->z << std::endl;
    std::cout << "( " << this->x << ", " << this->y << ", " << this->z << " )" << std::endl;
}

/**
 * @brief Rotates this vector around its z-axis.
 *
 * @param rad  Angle in radians to rotate about
 */
void Vektor::rotateZ(const double rad)
{
    double rotMat[2][3] = { {cos(rad), -sin(rad), 0}, {sin(rad), cos(rad), 0}};
    double row1 = x * rotMat[0][0] + y * rotMat[0][1] + z * rotMat[0][2];
    double row2 = x * rotMat[1][0] + y * rotMat[1][1] + z * rotMat[1][2];

    x = row1;
    y = row2;
}

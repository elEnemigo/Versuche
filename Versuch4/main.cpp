//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVI
// Versuch 04: Einführung in die Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Vektor.h"
#include <cmath>

#define PI 3.14159265359

/*
 * @brief Entrypoint
 */
int main()
{
    Vektor v1(8.0, -12.0, 6.0);// = new Vektor(3.0, 12.0, 4.0);
    Vektor v2(1.5, 6.0, 10.0);// = new Vektor(1.5, 6.0, 2.0);

    std::cout << "v1 = "; v1.ausgabe();
    std::cout << "v2 = "; v2.ausgabe();

    std::cout << "\nLength of v1: " << v1.length() << std::endl;
    std::cout << "Length of v2: " << v2.length() << std::endl;

    std::cout << std::endl << (Vektor::isOrthogonal(&v1, &v2)? "Orthogonal!" : "Not orthogonal!") << std::endl;

    std::cout << "\nv1+v2 = "; (v1+v2).ausgabe();//(Vektor::add(&v1, &v2))->ausgabe();
    std::cout << "v1 = v1-v2 = "; v1.subtract(&v2); v1.ausgabe();

    std::cout << "\nRotating v1 by 180 deg: "; v1.rotateZ(PI); v1.ausgabe();


    Vektor earth(0.0, 6371.0, 0.0);
    Vektor person(0.0, 0.0018, 0.0);
    person = person + earth;
    Vektor range = earth - person;

    int iter = 0;
    while (!Vektor::isOrthogonal(&earth, &range))
    {
        earth.rotateZ(0.000001);
        range = earth - person;

        iter++;
        if (iter > 10000000)
            break;
    }
    std::cout << "\nVisibility range for a height of 1.80m: " << range.length() << "km" << std::endl;
    std::cout << "Iterations: " << iter << std::endl;

    earth = *new Vektor(0.0, 6371.0, 0.0);
    person = *new Vektor(0.0, 0.5, 0.0);
    person = person + earth;
    range = earth - person;

    iter = 0;
    while (!Vektor::isOrthogonal(&earth, &range))
    {
        earth.rotateZ(0.00000001);
        range = earth - person;

        iter++;
        if (iter > 10000000)
            break;
    }
    std::cout << "\nVisibility range for a height of 500m: " << range.length() << "km" << std::endl;
    std::cout << "Iterations: " << iter << std::endl;

    return 0;
}

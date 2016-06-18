#include "street.h"

Street::Street(City* FirstCity, City* SecondCity)
    : A(FirstCity), B(SecondCity)
{

}

City* Street::getA() const
{
    return A;
}

City* Street::getB() const
{
    return B;
}

void Street::draw(QGraphicsScene& scene)
{
    // Draw line from A to B
    scene.addLine(A->getX() + CITYSIZE/2, A->getY() + CITYSIZE/2, B->getX() + CITYSIZE/2, B->getY() + CITYSIZE/2);
}

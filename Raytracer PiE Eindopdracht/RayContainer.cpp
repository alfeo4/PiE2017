#include "RayContainer.h"


Vector2<double> RayContainer::getRay()
    {
        ray[0] = distance;
        ray[1] = inclination;
        return ray;
    }


void RayContainer::setRay(double d, double i)
{
    ray[0] = d;
    ray[1] = i;
}

void RayContainer::setRay(Vector2<double> vector2)
{
    distance = vector2[0];
    inclination = vector2[1];
}

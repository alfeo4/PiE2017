#include "RayContainer.h"

void RayContainer::setRay(double d, double i)
{
    ray[0] = d;
    ray[1] = i;
}

void RayContainer::setRay(Vector2<double> vector2)
{
    ray[0] = vector2[0];
    ray[1] = vector2[1];
}

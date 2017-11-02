#include "RayContainer.h"


Vector2<double> RayContainer::getRay()
    {
        ray[0] = distance;
        ray[1] = inclination;
        return ray;
    }



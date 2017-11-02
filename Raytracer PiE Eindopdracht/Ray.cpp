#include "ray.h"


// Constructor that takes distance and inclination and puts them in a ray.

Ray::Ray(double distance, double inclination)
{
     Ray(distance, inclination) {setRay(distance, inclination);}
}

//Setter

void Ray::setRay(double distance, double inclination)
{
    ray[0] = distance;
    ray[1] = inclination;
}

//Getter

Vector2<double> Ray::getRay()
{
    return ray;
}

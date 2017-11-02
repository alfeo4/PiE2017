#ifndef RAYCONTAINER_H
#define RAYCONTAINER_H

#include "Vector2.h"



// RayContainer is a class containing rays. Rays can be added one by one. A RayContainer is returned.

class RayContainer
{
public:

    double getDistance() {return distance; }
    double getInclination() {return inclination; }
    void setDistance(double d) {distance = d; }
    void setInclination(double i) {inclination = i; }
    Vector2<double> getRay();




private:
    double distance, inclination;
    Vector2<double> ray;



};

#endif // RAYCONTAINER_H

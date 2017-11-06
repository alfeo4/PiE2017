#ifndef RAYCONTAINER_H
#define RAYCONTAINER_H

#include "Vector2.h"



// RayContainer is a class containing a single ray, with a distance from the
// optical axis, and an inclination tan(angle)

class RayContainer
{
public:

    double getDistance() {return ray[0]; }
    double getInclination() {return ray[1]; }
    void setDistance(double d) {ray[0] = d; }
    void setInclination(double i) {ray[1] = i; }
    Vector2<double> getRay() {return ray; }
    void setRay(double, double);
    void setRay(Vector2<double>);



private:
    Vector2<double> ray;



};

#endif // RAYCONTAINER_H

#ifndef RAY_H
#define RAY_H

#include <vector>
#include "Vector2.h"

// "Ray" is a class to hold rays. Each ray is a vector of two doubles, with the first element being distance and the second element being the inclination angle.
// Two constructors are offered (default and one which initialises values for distance and inclination), als well as a setter and getter.

class Ray
{
public:
    Ray();
    Ray(double, double);

    void setRay(double, double);
    Vector2<double> getRay();
private:
    Vector2<double> ray;

};


#endif // RAY_H

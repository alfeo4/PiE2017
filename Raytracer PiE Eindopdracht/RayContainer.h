#ifndef RAYCONTAINER_H
#define RAYCONTAINER_H


// RayContainer is a class containing a vector of rays. Rays can be added one by one. A RayContainer is returned.

class RayContainer
{
public:

    Raycontainer();

    vector<Ray> getRayContainer(){return rayContainer;}
    void addRay(Ray ray) {raycontainer.push_back(Ray ray);}


private:
    vector<Ray> rayContainer;

};

#endif // RAYCONTAINER_H

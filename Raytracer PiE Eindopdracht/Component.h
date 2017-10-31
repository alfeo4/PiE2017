#ifndef COMPONENT_H
#define COMPONENT_H

#include "Matrix22.h"

/* A base component class that contains a matrix with getter and setter.
*  This class is not meant to be instanced, only inherited from. The child class
*  is responsible for populating the matrix, since this is different between types of components.
*/

class Component
{
    public:
        void setMatrix(double A, double B, double C, double D);
        Matrix22<double> getMatrix();

    protected:
        Component() {}; // Protected constructor to prevent instancing.
        Matrix22<double> m_matrix;
};

#endif // COMPONENT_H

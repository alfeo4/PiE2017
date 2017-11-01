#ifndef SURFACE_H
#define SURFACE_H

#include "Component.h"


class Surface : public Component
{
    public:
        Surface(double curvatureRadius, double indexBefore, double indexAfter);

    private:
        double m_radius;
        double m_index1;
        double m_index2;

        void generateMatrix();
};

#endif // SURFACE_H

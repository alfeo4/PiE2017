#ifndef SURFACE_H
#define SURFACE_H

#include "Component.h"

/* A component class that represents refraction at a surface. Both curved and flat surfaces
*  are allowed. For a flat surface, set curvatureRadius to zero. A positive curvature radius
*  means a concave surface, i.e. its centre lies to the right of the surface.
*/

class Surface : public Component
{
    public:
        Surface(double curvatureRadius, double indexBefore, double indexAfter);

    private:
        double m_radius;
        double m_index1; // Refractive index of the medium before the surface.
        double m_index2; // Refractive index of the medium after the surface.

        void generateMatrix();
};

#endif // SURFACE_H

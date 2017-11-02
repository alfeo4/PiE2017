#ifndef MEDIUM_H
#define MEDIUM_H

#include "Component.h"

/* A component class that represents a transparent medium
*  with a given length. Refractive index is not relevant for
*  propagation, only for refraction at surfaces.
*/

class Medium : public Component
{
    public:
        Medium(double length);

    private:
        double m_length;

        // Generate the transfer matrix from the basic properties.
        void generateMatrix();
};

#endif // MEDIUM_H

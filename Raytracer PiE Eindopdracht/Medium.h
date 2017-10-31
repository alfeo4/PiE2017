#ifndef MEDIUM_H
#define MEDIUM_H

#include "Component.h"

/* A component class that represents a transparent medium,
*  with a length and a refractive index.
*/


class Medium : public Component
{
    public:
        // Two constructors, so the refractive index defaults to 1 when omitted.
        Medium(double length);
        Medium(double length, double index);

    private:
        double m_length;
        double m_index;

        // Generate the transfer matrix from the basic properties.
        void generateMatrix();
};

#endif // MEDIUM_H

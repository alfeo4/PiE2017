#ifndef OPTICALSYSTEM_H
#define OPTICALSYSTEM_H

#include <vector>
#include "Matrix22.h"

class Component;

/* OpticalSystem class that contains pointers to Components, so that the total transmission
*  matrix of the system can be calculated.
*/

class OpticalSystem
{
    public:
        OpticalSystem();
        ~OpticalSystem(); // Destructor required, because this class contains pointers.
        Matrix22<double> getMatrix();

        /* Add component to the system by pointer. NOTE: components may be destructed by
        *  the system object. */
        void addComponent(Component* component);
        void empty();   // Clear the system

    private:
        std::vector<Component*> m_components; // The list of components
        Matrix22<double> m_transferMatrix;

        void updateMatrix();
};

#endif // OPTICALSYSTEM_H

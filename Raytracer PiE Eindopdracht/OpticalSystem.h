#ifndef OPTICALSYSTEM_H
#define OPTICALSYSTEM_H

#include <vector>
#include "Matrix22.h"

class Component;

class OpticalSystem
{
    public:
        OpticalSystem();
        ~OpticalSystem();
        Matrix22<double> getMatrix();

        void addComponent(Component* component);
        void updateMatrix();

    private:
        std::vector<Component*> m_components;
        Matrix22<double> m_transferMatrix;
};

#endif // OPTICALSYSTEM_H

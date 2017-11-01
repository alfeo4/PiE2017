#include "OpticalSystem.h"
#include "Component.h"


OpticalSystem::OpticalSystem()
{
    //ctor
}

OpticalSystem::~OpticalSystem()
{
    for (Component* c : m_components)
    {
        delete c;
    }
}

Matrix22<double> OpticalSystem::getMatrix()
{
    return m_transferMatrix;
}

void OpticalSystem::addComponent(Component* component)
{
    m_components.push_back(component);
    updateMatrix();
}

void OpticalSystem::updateMatrix()
{
    m_transferMatrix[0] = 1;
    m_transferMatrix[1] = 0;
    m_transferMatrix[2] = 0;
    m_transferMatrix[3] = 1;

    for (Component* c : m_components)
    {
        m_transferMatrix = c->getMatrix() * m_transferMatrix;
    }
}

#include <vector>

#include "SystemContainer.h"
#include "OpticalSystem.h"
#include "Medium.h"
#include "Surface.h"

void populateSystem(OpticalSystem& system, std::vector<SystemContainer>& container)
{
    system.empty();
    for(std::vector<SystemContainer>::iterator it = container.begin(); it != container.end(); it++)
    {
        if (it->getType() == "Medium")
        {
            system.addComponent(new Medium(it->getDistance()));
        }
        if (it->getType() == "Surface")
        {
            double n1 = (it-1)->getRefractionIndex();
            double n2 = (it+1)->getRefractionIndex();
            system.addComponent(new Surface(it->getRadius(), n1, n2));
        }
    }
}

#include <vector>

#include "SystemContainer.h"
#include "OpticalSystem.h"
#include "Medium.h"
#include "Surface.h"

/* Populate an OpticalSystem object with components.
*  The function takes a SystemContainer vector containing the data on all the components.
*  The caller should check the SystemContainer objects are in the correct order (a Surface
*  should always be surrounded by two Medium objects)
*/

void populateSystem(OpticalSystem& system, std::vector<SystemContainer>& container)
{
    system.empty(); // Clear the system.

    // Use an iterator to loop over all of the objects in the container, as is the STL way.
    for(std::vector<SystemContainer>::iterator it = container.begin(); it != container.end(); it++)
    {
        if (it->getType() == "Medium")
        {
            system.addComponent(new Medium(it->getDistance())); // 'it' is a pointer, use -> for member selection.
        }
        if (it->getType() == "Surface")
        {
            double n1 = (it-1)->getRefractionIndex(); // get the index of the medium BEFORE this surface
            double n2 = (it+1)->getRefractionIndex(); // get the index of the medium AFTER this surface
            system.addComponent(new Surface(it->getRadius(), n1, n2));
        }
    }
}

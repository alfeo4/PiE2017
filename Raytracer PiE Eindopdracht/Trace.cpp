#include <vector>
#include "OpticalSystem.h"
#include "RayContainer.h"
#include "Trace.h"



std::vector<std::vector<double>> trace(std::vector<RayContainer> &inputRays, OpticalSystem &system)
{

    std::vector<std::vector<double>> distances;
    distances.resize(inputRays.size());

    std::vector<Component*> components = system.getComponents();

    for (unsigned int i = 0; i < inputRays.size(); i++)
    {
        vector<double> path;
        Vector2<double> traceRay = inputRays[i].getRay();

        path.push_back(traceRay[0]);

        for (unsigned int j = 0; j < components.size(); j++)
        {
            traceRay *= components[j]->getMatrix();

            if (j % 2 == 0)
            {
                path.push_back(traceRay[0]);

            }

        }
        distances.push_back(path);
    }

    return distances;
}

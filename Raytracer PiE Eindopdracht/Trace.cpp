#include <vector>
#include "OpticalSystem.h"
#include "RayContainer.h"
#include "Trace.h"

// Trace will take as arguments a vector of raycontainers and an optical system.
// The function then calculates for each ray the position of the ray (from the z-axis of the system) at a component.
// These distances are placed in a vector of doubles for each ray. Each vector belonging to a ray is then placed in another vector.
// This vector of vectors is returned by the function.

std::vector<std::vector<double>> trace(std::vector<RayContainer> &inputRays, OpticalSystem &system)
{
    // Declare and resize a return vector
    std::vector<std::vector<double>> distances;
    distances.resize(inputRays.size());
    // Get all components of the system
    std::vector<Component*> components = system.getComponents();

    // Loop over all rays. Make a vector named path which holds the distance values for this ray.
    for (unsigned int i = 0; i < inputRays.size(); i++)
    {
        vector<double> path;
        Vector2<double> traceRay = inputRays[i].getRay();
        // First, store the starting height of the ray
        path.push_back(traceRay[0]);
        // Loop over components. For each component, figure out how the ray is transformed and store this info.
        // Then, place the distance info in the path vector.
        for (unsigned int j = 0; j < components.size(); j++)
        {
            traceRay *= components[j]->getMatrix();
            // We only need half the distances as the others are duplicates, which is taken care of by this if-statement. Also, we aren't interested in the inclination, so we ignore it.
            if (j % 2 == 0)
            {
                path.push_back(traceRay[0]);

            }

        }
        // Add all distances for the ray to the distances vector.
        distances.push_back(path);
    }

    return distances;
}

#include <vector>
#include "Vector2.h"
#include "SystemContainer.h"
#include "Matrix22.h"
#include "RayContainer.h"
#include "CalculateOutput.h"


vector<RayContainer> calculateOutput(vector<RayContainer> &inputRays, OpticalSystem &system)
{
    vector<RayContainer> outputRays;
    for (int i = 0; i < inputRays.size(); i++)
    {
        Vector2<double> ray;
        RayContainer container;
        ray = system.getMatrix() * inputRays[i].getRay();
        container.setRay(ray);
        outputRays.push_back(container);
    }

    return outputRays;

}

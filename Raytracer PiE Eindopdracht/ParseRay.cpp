#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "parseRay.h"

std::vector<RayContainer> parseRay(std::vector<std::string> input)
{
    double val1, val2;
    std::vector<RayContainer> rayContainer;

    for (unsigned int i = 0; i < input.size(); i++)
    {
        RayContainer ray;
        std::stringstream ss;
        ss << input[i];
        ss >> val1 >> val2;

        ray.setDistance(val1);
        ray.setInclination(val2);
        rayContainer.push_back(ray);
    }
    return rayContainer;

}



#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "SystemContainer.h"
#include "parseSystem.h"

using namespace std;


std::vector<SystemContainer> parseSystem(std::vector<string> input)
{

    // Loop over all elements of input. The elements of input are strings,
    //  containing an identifying string (the type, for example free space propagation or thin lens) and three doubles,
    // representing respectively the distance from origin, the radius of curvature and the refractive index.
    // These need to be extracted. and will be placed in the SystemContainer, using the function parseSystem.
    // NOTE: radius of curvature applies only to lenses and curved mirrors. For other types, a value of 99999999 will be used to show an infinite radius of curvature, which represents a flat surface.
    string type;
    double val1, val2, val3;
    vector<SystemContainer> systemContainer;

    for (int i = 0; i < input.size(); i++)
    {
        // Here, a SystemContainer is instantiated and filled with data.
        // A stringstream is used to extract from each string the type and the three double values.
        SystemContainer data;
        stringstream ss;
        ss << input[i];
        ss >> type >> val1 >> val2 >> val3;

        data.setType(type);
        data.setDistance(val1);
        data.setRadius(val2);
        data.setRefractionIndex(val3);
        systemContainer.push_back(data);

    }
    return systemContainer;

}
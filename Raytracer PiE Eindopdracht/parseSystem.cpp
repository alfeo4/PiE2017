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
    double val1, val2;
    vector<SystemContainer> systemContainer;

    bool b = 0; // Used when checking whether the order of types is proper.

    for (unsigned int i = 0; i < input.size(); i++)
    {
        // Here, a SystemContainer is instantiated and filled with data.
        // A stringstream is used to extract from each string the type and the three double values.
        SystemContainer data;
        stringstream ss;
        ss << input[i];
        ss >> type >> val1 >> val2;

        // Check what type is offered.
        // Media only need a type and a distance, so the others are set to 0.
        // Surface needs a type, a radius and an index, so distance is set to 0.

        if (type == "Medium")
        {
            data.setType(type);
            data.setDistance(val1);
            data.setRadius(0);
            data.setRefractionIndex(val2);

        }

        else if (type == "Surface")
        {
            data.setType(type);
            data.setDistance(0);
            data.setRadius(val1);
            data.setRefractionIndex(0);

        }

        // In case a nonexistent type is specified, an error is thrown.

        else
        {
            std::cerr << "Error in SystemContainer: type not recognised. \n";
        }


        // Every system should start and end with a medium. No two media can follow one another, and nor can two surfaces. The following if-statements check whether this is the case.
        if ((data.getType() == "Surface" ) && (b == 0)) {std::cerr << "Error: unexpected type (surface/medium) in parseSystem \n" ;}
        if ((data.getType() == "Medium" ) && (b == 1)) {std::cerr << "Error: unexpected type (surface/medium) parseSystem \n" ;}
        b = !b;


        systemContainer.push_back(data);

    }



    return systemContainer;

}

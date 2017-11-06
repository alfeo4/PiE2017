#include <vector>
#include <fstream>
#include <string>
#include <iostream>

#include "RayContainer.h"

/* Write a RayContainer vector to a file. Each ray on a new line with distance and inclination
*  separated by a space.
*/

void writeRays(const std::vector<RayContainer>& rays, const std::string fileName)
{
    std::ofstream outFile(fileName.c_str(), std::ios::out);

    if(!outFile.is_open())
    {
        std::cerr << "Could not open file: " << fileName << std::endl;
        return;
    }

    for(RayContainer ray : rays)
    {
        outFile << ray.getDistance() << " " << ray.getInclination() << '\n';
    }

    std::cout << "Output written to " << fileName << std::endl;
    outFile.close();

}

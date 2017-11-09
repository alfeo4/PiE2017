#include "WriteDistances.h"

// A function which writes the distances, as calculated by the trace function, to a file.

void writeDistances(const std::vector<std::vector<double>>& distances, const std::string fileName)
{
    // open a file writing stream
    std::ofstream outFile(fileName.c_str(), std::ios::out);
    // Check if opening was successful
    if(!outFile.is_open())
    {
        std::cerr << "Could not open file: " << fileName << std::endl;
        return;
    }
    // Write all distances to a file, so that each line contains all distances of each ray
    for (unsigned int i = 0; i < distances.size(); i++)
    {
        for (unsigned int j = 0; j < distances[i].size(); j++)
        {
            outFile << distances[i][j] << " ";
        }
        outFile << std::endl;
    }
    outFile.close();

}

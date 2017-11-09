#include "WriteDistances.h"

void writeDistances(const std::vector<std::vector<double>>& distances, const std::string fileName)
{
    std::ofstream outFile(fileName.c_str(), std::ios::out);

    if(!outFile.is_open())
    {
        std::cerr << "Could not open file: " << fileName << std::endl;
        return;
    }

    for (unsigned int i = 0; i < distances.size(); i++)
    {
        for (unsigned int j = 0; j < distances[i].size(); j++)
        {
            outFile << distances[i][j] << " ";
        }
        outFile << std::endl;
    }

}

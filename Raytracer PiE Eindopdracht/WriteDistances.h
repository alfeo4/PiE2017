
#ifndef WRITEDISTANCES_H
#define WRITEDISTANCES_H

#include <vector>
#include "RayContainer.h"
#include <iostream>
#include <fstream>

void writeDistances(const std::vector<std::vector<double>>& rays, const std::string fileName);

#endif // WRITEDISTANCES_H

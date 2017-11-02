#ifndef RAYINPUT_H
#define RAYINPUT_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "RayContainer.h"

// RayInput will be used to to get rays from a file.
// The file will contain lines with two doubles (distance and inclination, respectively),
// separated by a whitespace.
// RayInput will take those rays and place them in the RayContainer.

std::vector<RayContainer> parseRay(std::vector<std::string>);

#endif // RAYINPUT_H

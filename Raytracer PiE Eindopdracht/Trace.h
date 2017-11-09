#ifndef TRACE_H
#define TRACE_H

#include <vector>
#include "OpticalSystem.h"
#include "RayContainer.h"
#include "SystemContainer.h"
#include "Component.h"



std::vector<std::vector<double>> trace(std::vector<RayContainer>&, OpticalSystem&);


#endif // TRACE_H

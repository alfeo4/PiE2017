#ifndef CALCULATEOUTPUT_H
#define CALCULATEOUTPUT_H

#include <vector>
#include "Vector2.h"
#include "SystemContainer.h"
#include "Matrix22.h"
#include "RayContainer.h"
#include "OpticalSystem.h"



vector<RayContainer> calculateOutput(vector<RayContainer>&, OpticalSystem&);


#endif // CALCULATEOUTPUT_H

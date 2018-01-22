#include <iostream>
#include <vector>
#include "SystemContainer.h"
#include "Medium.h"
#include "Vector2.h"
#include "Surface.h"
#include "OpticalSystem.h"
#include "RayContainer.h"

#include "openFile.h"
#include "parseSystem.h"
#include "parseRay.h"
#include "populateSystem.h"

#include "calculateOutput.h"
#include "writeRays.h"
#include "expandLenses.h"

#include "trace.h"
#include "writeDistances.h"

using namespace std;

/* The Raytracer program reads rays from an inrays.txt file and traces them through a
*  system as defined by lenses.txt or components.txt (in advanced mode).
*  The output is written as outrays.txt for the beam positions and angles after passing
*  through the system, and raypaths.txt for the full path. This last file is used by
*  drawsystem.m for visualisation (requires MATLAB).
*/

int main()
{
    // Use components file directly or create it from lenses
    cout << "Use advanced mode? (y/n)";
    char answer;
    cin >> answer;

    if (answer == 'y')
    {
        cout << "Using components.txt" << endl;
    }
    else{
        expandLenses("lenses.txt","components.txt");
        cout << "Built components.txt from lenses.txt" << endl;
    }

    // Load the optical system
    vector<SystemContainer> components = parseSystem(openFile("components.txt"));

    OpticalSystem system;
    populateSystem(system, components);

    // Load rays
    vector<string> rayList = openFile("inrays.txt");
    vector<RayContainer> rays = parseRay(rayList);

    // Simulate
    vector<RayContainer> outrays = calculateOutput(rays, system);
    vector<vector<double>> tracetest = trace(rays, system);

    writeDistances(tracetest, "raypaths.txt");

    // Write output
    writeRays(outrays, "outrays.txt");

    return 0;
}


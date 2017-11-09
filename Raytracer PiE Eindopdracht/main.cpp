#include <iostream>
#include <vector>
#include "SystemContainer.h"
#include "Medium.h"
#include "Vector2.h"
#include "Surface.h"
#include "OpticalSystem.h"
#include "RayContainer.h"

#include "fileInput.h"
#include "parseSystem.h"
#include "ParseRay.h"
#include "populateSystem.h"

#include "CalculateOutput.h"
#include "writeRays.h"
#include "expandLenses.h"

#include "Trace.h"
#include "WriteDistances.h"

using namespace std;

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

    writeDistances(tracetest, "distancetest01.txt");

    // Write output
    writeRays(outrays, "outrays.txt");

    return 0;
}


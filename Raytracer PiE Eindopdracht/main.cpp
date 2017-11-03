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

using namespace std;

int main()
{
    cout << "Use advanced mode? (y/n)";
    char answer;
    cin >> answer;

    if (answer == 'n')
    {
        expandLenses("lenses.txt","components.txt");
        cout << "Built components.txt from lenses.txt" << endl;
    }
    else{
        cout << "Using components.txt" << endl;
    }

    Vector2<double> vec;
    vec[0] = 1;
    vec[1] = -.1;

    vector<SystemContainer> components = parseSystem(openFile("components.txt"));

    OpticalSystem system;
    populateSystem(system, components);

    vec *= system.getMatrix();

    cout << vec[0] << endl;
    cout << vec[1] << endl;

    vector<string> rayList = openFile("inrays.txt");
    vector<RayContainer> rays = parseRay(rayList);

    vector<RayContainer> outrays = calculateOutput(rays, system);

    writeRays(outrays, "outrays.txt");

    return 0;
}


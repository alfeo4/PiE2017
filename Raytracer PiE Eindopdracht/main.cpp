#include <iostream>
#include "Medium.h"
#include "Vector2.h"
#include "Surface.h"
#include "OpticalSystem.h"

#include "fileInput.h"
#include "parseSystem.h"
#include "populateSystem.h"

using namespace std;

int main()
{
    Vector2<double> vec;
    vec[0] = 0.5;
    vec[1] = 0.1;

    vector<string> componentList = openFile("components.txt");
    vector<SystemContainer> components = parseSystem(componentList);

    OpticalSystem system;

    populateSystem(system, components);

    vec *= system.getMatrix();

    cout << vec[0] << endl;
    cout << vec[1] << endl;
    return 0;
}


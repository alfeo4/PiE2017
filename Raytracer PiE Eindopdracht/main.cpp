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
#include "populateSystem.h"
#include "parseRay.h"
#include "CalculateOutput.h"

using namespace std;

int main()
{
    string filepath = "components.txt";
    vector<string> test0 = openFile(filepath);
    vector<SystemContainer> test1 = parseSystem(test0);
    OpticalSystem test2;
    populateSystem(test2, test1);


    string filepath2 = "inrays.txt";
    vector<string> test99 = openFile(filepath2);
    vector<RayContainer> test98 = parseRay(test99);

    // calculateOutput(test98, test2);

     vector<RayContainer> output = calculateOutput(test98, test2);
     cout << output[0].getDistance() << endl;


    cout << "test" << endl;
    return 0;
}


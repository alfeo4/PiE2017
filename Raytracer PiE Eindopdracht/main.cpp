#include <iostream>
#include <vector>
#include "SystemContainer.h"
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
    filepath = "Test_for_file_io.txt";
    vector<string> test0 = openFile(filepath);
    vector<SystemContainer> test1 = parseSystem(test0);
    OpticalSystem test2 =



    filepath2 = "Test_for_ray_io.txt";
    vector<string> test99 = openFile(filePath2);
    vector<RayContainer> test98 = parseRay(test99);

    vector<RayContainer> output = calculateOutput(test98, test2);
    cout << output[0].getDistance() << endl;
}


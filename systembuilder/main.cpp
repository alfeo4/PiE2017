#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "fileInput.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;

    vector<string> lensList = openFile("lenses.txt");

    vector<string> out;

    for(const string& line : lensList)
    {
        if (line[0] == '#') continue; // For comments


    }

}

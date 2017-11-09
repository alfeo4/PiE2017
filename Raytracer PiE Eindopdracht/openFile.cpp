

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "openFile.h"



std::vector<std::string> openFile(std::string nameOfFile)
{

    using namespace std;

    //filepath = "C:/Users/User/Documents/PiE/Eindopdracht/PiE2017/Raytracer PiE Eindopdracht/Test_for_file_io.txt";
    const char * file = nameOfFile.c_str(); // ifstream doesn't like strings, so change to a const char*

    //Create an input stream to read the file line by line and put the resulting info into string array input, with one line per index.
    string line;
    vector<string> input;

    ifstream ins (file);
    if (ins.is_open()) // Check if the file is opened correctly
    {
        while (getline(ins, line)) // Read lines until there are no more lines
        {
            if (line[0] != '#') // Ignore lines starting with '#' (comments)
                input.push_back(line); // Push each line into a string vector
        }
    }

    else
    {
        cerr << "Error opening file, program terminating. " << endl;

    }
    ins.close();
    return input;


}








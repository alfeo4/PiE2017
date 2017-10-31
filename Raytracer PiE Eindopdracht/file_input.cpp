

#include <fstream>
#include <string>
#include <vector>
#include <iostream>



main()
{

    using namespace std;
    //Ask user which file to read
    string filepath;
/*
    cout << "please type full path to file: " << endl;
    cin >> filepath;
*/
    filepath = "C:/Users/User/Documents/PiE/Eindopdracht/PiE2017/Raytracer PiE Eindopdracht/Test_for_file_io.txt";
    const char * file = filepath.c_str(); // ifstream doesn't like strings, so change to a const char*

    //Create an input stream to read the file line by line and put the resulting info into string array input, with one line per index.
    string line;
    vector<string> input;

    ifstream ins (file);
    if (ins.is_open())
    {
        while (getline(ins, line))
        {
            input.push_back(line);
        }
    }
    else
    {
        cerr << "Error opening file, program terminating. " << endl;

    }
    ins.close();


    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << endl;
    }







}


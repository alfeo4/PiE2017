#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "fileInput.h"

using namespace std;

/* Expand a file containing lenses to a file containing surfaces and media.
*  This allows for easy definition of an optical system by specifying focal lengths
*  and let the software handle converting those to surfaces and media.
*  For the conversion, a thin, symmetrical lens is assumed. If different lens types are
*  required, the components file should be used directly.
*/

void expandLenses(string lensfile, string componentfile)
{
    vector<string> lensList = openFile(lensfile.c_str()); // Load lenslist into a vector of strings

    ofstream outfile(componentfile.c_str(), ios::out); // File for writing components

    if(!outfile.is_open())
    {
        cerr << "Could not open file" << endl;
    }

    outfile << "# Auto-generated components file" << endl;

    for(const string& line : lensList)
    {
        // Put line in stringstream for easy extraction of data
        stringstream linestream;
        linestream << line;
        string type;
        linestream >> type;
        if (type != "Lens") // Only expand lens components, the rest is written directly to the output file.
        {
            outfile << line << endl;
            continue;
        }


        // Expand a lens as a surface-medium-surface combination.
        // Assume thin, symmetrical lens.
        double f, n;
        linestream >> f >> n;

        double R = 2*f *(n-1);

        outfile << "Surface " << R << endl;
        outfile << "Medium " << 0 << " " << n << endl;
        outfile << "Surface " << -1*R << endl;
    }

    outfile.close();
}

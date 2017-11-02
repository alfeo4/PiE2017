#ifndef SYSTEMCONTAINER_H
#define SYSTEMCONTAINER_H

#include<string>
#include <sstream>


// Class SystemContainer is designed to hold the data from the system input file in a more usable format.
//  Data is extracted from a file by function fileInput and placed in a string vector.
//  Function parseSystem extracts the data from the string vector and places it in the SystemContainer.


using namespace std;
class SystemContainer
{
private:

    string type;
    double distance, radius, refractionIndex;

public:
    string getType() {return type;}
    double getDistance() {return distance;}
    double getRadius() {return radius;}
    double getRefractionIndex() {return refractionIndex;}
    void setType(string s) {type = s;}
    void setDistance(double d) {distance = d;}
    void setRadius(double r) {radius = r;}
    void setRefractionIndex(double ri) {refractionIndex = ri;}

};



#endif // SystemContainer_H

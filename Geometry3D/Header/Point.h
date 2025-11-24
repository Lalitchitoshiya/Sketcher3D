#pragma once
#include "Export.h"
#include <iostream>
using namespace std;

class GEOMETRY3D_API Point {
public:
    double x, y, z;

    //Point(){}
    Point(double X, double Y, double Z);
    ~Point();
    std::string toString() const; // clean & simple
};


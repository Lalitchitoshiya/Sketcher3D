//#pragma once
//#include "Shape.h"
//#include "Point.h"
//#include "Export.h"
//class GEOMETRY3D_API Cylinder : public Shape {
//    Point baseCenter;   // base center point (x, y, z)
//    double height;      // length of cylinder
//    double diameter;    // diameter of base
//
//public:
//    // cx,cy,cz = base center, h = height (length), d = diameter
//    Cylinder(double cx, double cy, double cz, double h, double d);
//
//    std::string getName() const override;
//    void savePoints(const std::string& filename) const override;
//    void saveParams(const std::string& filename) const override;
//};

#pragma once
#include "Shape.h"
#include "Point.h"
#include "Export.h"

class GEOMETRY3D_API Cylinder : public Shape {
    Point base;
    double height;
    double diameter;

public:
    Cylinder(const Point& b, double h, double d);

    std::string getName() const override;
    void savePoints(const std::string& file) const override;
    void saveParams(const std::string& file) const override;
};



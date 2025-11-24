//#pragma once
//#include "Shape.h"
//#include "Point.h"
//#include "Export.h"
//class GEOMETRY3D_API Sphere : public Shape {
//
//    Point center;
//    double radius;
//
//public:
//    Sphere(double cx, double cy, double cz, double r);
//
//    std::string getName() const override;
//    void savePoints(const std::string& file) const override;
//    void saveParams(const std::string& file) const override;
//};

#pragma once
#include "Shape.h"
#include "Point.h"
#include "Export.h"

class GEOMETRY3D_API Sphere : public Shape {
    Point center;
    double radius;

public:
    Sphere(const Point& c, double r);

    std::string getName() const override;
    void savePoints(const std::string& file) const override;
    void saveParams(const std::string& file) const override;
};


//#pragma once
//#include "Shape.h"
//#include "Point.h"
//#include "Export.h"
//class GEOMETRY3D_API Sphere : public Shape {
//    Point center;
//    double radius;
//
//public:
//    Sphere(double cx, double cy, double cz, double r);
//
//    std::string getName() const override;
//    void savePoints(const std::string& filename) const override;
//    void saveParams(const std::string& filename) const override;
//};


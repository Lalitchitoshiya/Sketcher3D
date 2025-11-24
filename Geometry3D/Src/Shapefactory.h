//#pragma once
//#include <memory>
//#include <string>
//#include "Cuboid.h"
//#include "Sphere.h"
//#include "Cylinder.h"
//#include "Export.h"
//class GEOMETRY3D_API ShapeFactory {
//public:
//    static std::unique_ptr<Shape> create(
//        const std::string& type,
//        const double params[],
//        int count);
//};


#pragma once
#include <memory>
#include <string>

#include "Cuboid.h"
#include "Sphere.h"
#include "Cylinder.h"

class ShapeFactory {
public:
    static std::unique_ptr<Shape> create(
        const std::string& type,
        const double params[],
        int count);
};

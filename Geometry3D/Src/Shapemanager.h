//#pragma once
//#include <vector>
//#include <memory>
//#include <string>
//#include "Shape.h"
//#include "Export.h"
//
//class GEOMETRY3D_API ShapeManager {
//    std::vector<std::unique_ptr<Shape>> shapes;
//
//public:
//    void add(std::unique_ptr<Shape> s);
//    void saveAll();
//};


#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

class ShapeManager {
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    void add(std::unique_ptr<Shape> s);
    void saveAll();
};

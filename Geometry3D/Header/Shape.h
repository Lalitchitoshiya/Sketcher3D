#pragma once
#include <string>
#include "Export.h"
class GEOMETRY3D_API Shape {
public:
    std::string shape_name;
    	Shape() {};
    	Shape(std::string& n);
    	virtual ~Shape();

    // Returns shape name like "Cuboid", "Sphere"
    virtual std::string getName() const = 0;

    // Writes points suitable for GNU plot (.dat file)
    virtual void savePoints(const std::string& filename) const = 0;

    // Writes parameters like length/radius/height (.txt file)
    virtual void saveParams(const std::string& filename) const = 0;
};




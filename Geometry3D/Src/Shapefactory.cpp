#include "ShapeFactory.h"
#pragma once
#include <memory>
#include <string>
#include "Cuboid.h"
#include "Sphere.h"
#include "Cylinder.h"
std::unique_ptr<Shape> ShapeFactory::create(
    const std::string& type,
    const double params[],
    int count)
{
    if (type == "cuboid" && count == 6)
        return std::make_unique<Cuboid>(
            params[0], params[1], params[2],
            params[3], params[4], params[5]);

    if (type == "sphere" && count == 4)
        return std::make_unique<Sphere>(
            params[0], params[1], params[2], params[3]);



    if (type == "cylinder" && count == 5)
        return std::make_unique<Cylinder>(
            params[0], params[1], params[2],  // base center
            params[3],                        // height (length)
            params[4]);                       // diameter

    return nullptr;
}

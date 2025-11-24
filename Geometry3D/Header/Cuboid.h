#pragma once
#include "Export.h"
#include "Shape.h"
#include "Point.h"
#include <vector>

class GEOMETRY3D_API Cuboid : public Shape {
    Point p1, p2;

public:
    Cuboid(double x1, double y1, double z1,
        double x2, double y2, double z2);

    std::string getName() const override;
    void savePoints(const std::string& file) const override;
    void saveParams(const std::string& file) const override;
};

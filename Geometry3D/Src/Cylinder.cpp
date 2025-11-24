
#include "Cylinder.h"
#include <fstream>
#include <cmath>

Cylinder::Cylinder(const Point& b, double h, double d)
    : base(b), height(h), diameter(d) {
}

std::string Cylinder::getName() const {
    return "Cylinder";
}

void Cylinder::savePoints(const std::string& file) const {
    std::ofstream out(file);
    double r = diameter / 2.0;

    for (int i = 0; i <= 10; i++) {
        double t = (double)i / 10;
        double z = base.z + t * height;

        for (int j = 0; j <= 20; j++) {
            double ang = j * (2 * 3.14159 / 20);
            double x = base.x + r * cos(ang);
            double y = base.y + r * sin(ang);

            out << Point(x, y, z).toString() << "\n";
        }
        out << "\n";
    }
}

void Cylinder::saveParams(const std::string& file) const {
    std::ofstream out(file);
    out << "shape: cylinder\n";
    out << "length: " << height << "\n";
    out << "diameter: " << diameter << "\n";
}

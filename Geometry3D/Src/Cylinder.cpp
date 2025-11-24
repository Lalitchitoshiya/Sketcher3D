#include "Cylinder.h"
#include <fstream>
#include <cmath>

Cylinder::Cylinder(double cx, double cy, double cz, double h, double d)
    : baseCenter(cx, cy, cz), height(h), diameter(d) {
}

std::string Cylinder::getName() const {
    return "Cylinder";
}

void Cylinder::savePoints(const std::string& filename) const {
    std::ofstream out(filename);

    const int radialSteps = 20;  // circle resolution
    const int heightSteps = 10;  // vertical resolution
    const double PI = 3.141592653589793;
    double radius = diameter / 2.0;

    // Make circles along height
    for (int i = 0; i <= heightSteps; ++i) {
        double t = static_cast<double>(i) / heightSteps;
        double z = baseCenter.z + t * height;

        for (int j = 0; j <= radialSteps; ++j) {
            double angle = static_cast<double>(j) / radialSteps * 2.0 * PI;
            double x = baseCenter.x + radius * std::cos(angle);
            double y = baseCenter.y + radius * std::sin(angle);

            out << Point(x, y, z).toString() << "\n";
        }
        out << "\n";   // blank line: separate each ring (good for gnuplot with lines)
    }
}

void Cylinder::saveParams(const std::string& filename) const {
    std::ofstream out(filename);
    out << "shape: cylinder\n";
    out << "length: " << height << "\n";   // as you wanted: length
    out << "diameter: " << diameter << "\n";
}

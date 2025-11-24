#include "Sphere.h"
#include <fstream>
#include <cmath>

Sphere::Sphere(double x, double y, double z, double r)
    : center(x, y, z), radius(r)
{
}

std::string Sphere::getName() const {
    return "Sphere";
}

void Sphere::savePoints(const std::string& file) const {
    std::ofstream out(file);

    int steps = 20;

    for (int i = 0; i <= steps; i++) {
        double lat = -3.14 / 2 + i * (3.14 / steps);

        for (int j = 0; j <= steps; j++) {
            double lon = j * (2 * 3.14 / steps);

            double xx = center.x + radius * cos(lat) * cos(lon);
            double yy = center.y + radius * cos(lat) * sin(lon);
            double zz = center.z + radius * sin(lat);

            out << Point(xx, yy, zz).toString() << "\n";
        }
        out << "\n";
    }
}

void Sphere::saveParams(const std::string& file) const {
    std::ofstream out(file);
    out << "shape: sphere\n";
    out << "radius: " << radius << "\n";
}

#include "Sphere.h"
#include <fstream>
#include <cmath>

Sphere::Sphere(const Point& c, double r)
    : center(c), radius(r) {
}

std::string Sphere::getName() const {
    return "Sphere";
}

void Sphere::savePoints(const std::string& file) const {
    std::ofstream out(file);

    int steps = 20;

    for (int i = 0; i <= steps; i++) {
        double lat = -3.14159 / 2 + i * (3.14159 / steps);

        for (int j = 0; j <= steps; j++) {
            double lon = j * (2 * 3.14159 / steps);

            double x = center.x + radius * cos(lat) * cos(lon);
            double y = center.y + radius * cos(lat) * sin(lon);
            double z = center.z + radius * sin(lat);

            out << Point(x, y, z).toString() << "\n";
        }
        out << "\n";
    }
}

void Sphere::saveParams(const std::string& file) const {
    std::ofstream out(file);
    out << "shape: sphere\n";
    out << "radius: " << radius << "\n";
}



//#include "pch.h"
//#include "Sphere.h"
//#include <fstream>
//#include <cmath>
//
//Sphere::Sphere(double cx, double cy, double cz, double r)
//    : center(cx, cy, cz), radius(r) {
//}
//
//std::string Sphere::getName() const { return "Sphere"; }
//
//void Sphere::savePoints(const std::string& file) const {
//    std::ofstream out(file);
//    int steps = 20;
//
//    for (int i = 0; i <= steps; i++) {
//        double lat = -3.14 / 2 + i * (3.14 / steps);
//        for (int j = 0; j <= steps; j++) {
//            double lon = j * (2 * 3.14 / steps);
//            double x = center.x + radius * cos(lat) * cos(lon);
//            double y = center.y + radius * cos(lat) * sin(lon);
//            double z = center.z + radius * sin(lat);
//            out << Point(x, y, z).toString() << "\n";
//        }
//        out << "\n";
//    }
//}
//
//void Sphere::saveParams(const std::string& file) const {
//    std::ofstream out(file);
//    out << "shape: sphere\n";
//    out << "radius: " << radius << "\n";
//}

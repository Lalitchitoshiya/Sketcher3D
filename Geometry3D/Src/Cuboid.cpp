#include "Cuboid.h"
#include <fstream>
#include<vector>
#include "Point.h"
#include <algorithm>

Cuboid::Cuboid(double x1, double y1, double z1, double x2, double y2, double z2)
    : p1(x1, y1, z1), p2(x2, y2, z2) {
}

std::string Cuboid::getName() const {
    return "Cuboid";
}

void Cuboid::savePoints(const std::string& file) const {
    std::ofstream out(file);

    double xmin = std::min(p1.x, p2.x);
    double xmax = std::max(p1.x, p2.x);
    double ymin = std::min(p1.y, p2.y);
    double ymax = std::max(p1.y, p2.y);
    double zmin = std::min(p1.z, p2.z);
    double zmax = std::max(p1.z, p2.z);

    // vertices
    std::vector <Point> v = {
        {xmin,ymin,zmin},{xmax,ymin,zmin},{xmax,ymax,zmin},{xmin,ymax,zmin},
        {xmin,ymin,zmax},{xmax,ymin,zmax},{xmax,ymax,zmax},{xmin,ymax,zmax}
    };

    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for (auto& e : edges) {
        out << v[e[0]].toString() << "\n";
        out << v[e[1]].toString() << "\n\n";
    }
}

void Cuboid::saveParams(const std::string& file) const {
    std::ofstream out(file);
    out << "shape: cuboid\n";
    out << "length: " << std::abs(p2.x - p1.x) << "\n";   //abs is mode value
    out << "width: " << std::abs(p2.y - p1.y) << "\n";
    out << "height: " << std::abs(p2.z - p1.z) << "\n";
}

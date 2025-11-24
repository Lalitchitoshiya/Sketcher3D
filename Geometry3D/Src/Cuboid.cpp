#include "Cuboid.h"
#include <fstream>
#include<vector>
#include "Point.h"
#include <algorithm>

Cuboid::Cuboid(const Point& P1, const Point& P2)
    : P1(P1), P2(P2) {
}

std::string Cuboid::getName() const {
    return "Cuboid";
}

void Cuboid::savePoints(const std::string& file) const {
    std::ofstream out(file);

    double xmin = std::min(P1.x, P2.x);
    double xmax = std::max(P1.x, P2.x);
    double ymin = std::min(P1.y, P2.y);
    double ymax = std::max(P1.y, P2.y);
    double zmin = std::min(P1.z, P2.z);
    double zmax = std::max(P1.z, P2.z);

    Point v[8] = {
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
    out << "length: " << std::abs(P2.x - P1.x) << "\n";
    out << "width: " << std::abs(P2.y - P1.y) << "\n";
    out << "height: " << std::abs(P2.z - P1.z) << "\n";
}

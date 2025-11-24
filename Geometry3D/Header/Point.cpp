#include "Point.h"
#include <sstream>

Point :: Point(double x, double y, double z) : x(x), y (y), z(z) {}

Point::~Point(){}

std::string Point::toString() const {
    std::ostringstream ss;
    ss << x << " " << y << " " << z;
    return ss.str();
}


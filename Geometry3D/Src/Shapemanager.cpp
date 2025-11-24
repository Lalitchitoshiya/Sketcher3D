#include "ShapeManager.h"

void ShapeManager::add(std::unique_ptr<Shape> s) {
    shapes.push_back(std::move(s));
}

void ShapeManager::saveAll() {
    for (size_t i = 0; i < shapes.size(); i++) {
        std::string name = shapes[i]->getName() + "_" + std::to_string(i);

        shapes[i]->savePoints(name + "_points.dat");
        shapes[i]->saveParams(name + "_params.txt");
    }
}

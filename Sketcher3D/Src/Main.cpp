
#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "Shape.h"
#include "Cuboid.h"
#include "Sphere.h"
#include "Point.h"

// Global container for shapes
std::vector<std::unique_ptr<Shape>> shapes;

// (local) wrapper to store shapes
void add(std::unique_ptr<Shape> s) {
    shapes.push_back(std::move(s));
}

// Save all shapes
void SaveAllShapes() {
    for (size_t i = 0; i < shapes.size(); i++) {

        std::string base = shapes[i]->getName() + "_" + std::to_string(i);

        shapes[i]->savePoints(base + "_points.dat");
        shapes[i]->saveParams(base + "_params.txt");
    }
}


// AddShape 

void AddShape(const char* name, double* params, int count)
{
    if (!name || !params) {
        std::cerr << "AddShape: null args\n";
        return;
    }

    std::string n(name);

    
    if (n == "cuboid")
    {
        if (count < 6) {
            std::cerr << "Cuboid needs 6 params\n";
            return;
        }

        // Your Cuboid constructor: Cuboid(Point, Point)
        Point p1(params[0], params[1], params[2]);
        Point p2(params[3], params[4], params[5]);

        add(std::make_unique<Cuboid>(p1, p2));
        return;
    }


    if (n == "sphere")
    {
        if (count < 4) {
            std::cerr << "Sphere needs 4 params\n";
            return;
        }

        // Your Sphere constructor: Sphere(Point, radius)
        Point center(params[0], params[1], params[2]);
        double radius = params[3];

        add(std::make_unique<Sphere>(center, radius));
        return;
    }

    std::cerr << "Unknown shape: " << name << "\n";
}



// MAIN FUNCTION

int main()
{
    std::cout << "=== Sketcher3D Shape Creator ===\n";

    while (true)
    {
        std::cout << "\nEnter shape name (cuboid / sphere) or 'exit': ";
        std::string shape;
        std::cin >> shape;

        if (shape == "exit")
            break;

        if (shape == "cuboid")
        {
            double p[6];
            std::cout << "Enter x1 y1 z1 x2 y2 z2: ";
            std::cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5];

            AddShape("cuboid", p, 6);
            std::cout << "Cuboid added!\n";
        }
        else if (shape == "sphere")
        {
            double p[4];
            std::cout << "Enter cx cy cz radius: ";
            std::cin >> p[0] >> p[1] >> p[2] >> p[3];

            AddShape("sphere", p, 4);
            std::cout << "Sphere added!\n";
        }
        else
        {
            std::cout << "Unknown shape!\n";
        }
    }

    std::cout << "\nSaving all shapes...\n";
    SaveAllShapes();

    std::cout << "Done! Check for .dat and .txt files.\n";
    return 0;
}

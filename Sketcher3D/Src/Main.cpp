#include <iostream>
#include <string>

// Import DLL functions
//extern "C" {
//    __declspec(dllimport) void AddShape(const char* name, double* params, int count);
//    __declspec(dllimport) void SaveAllShapes();
//}

void AddShape(const char* name, double* params, int count);
void SaveAllShapes();

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

    std::cout << "Done! Check your DLL folder for .dat and .txt files.\n";
    return 0;
}

void AddShape(const char* name, double* params, int count)
{
}

void SaveAllShapes()
{
}

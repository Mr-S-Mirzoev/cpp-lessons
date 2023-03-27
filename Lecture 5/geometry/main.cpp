#include "rectangle.h"
#include "triangle.h"
#include <iostream>

int main()
{
    double one, two;

    std::cout << "Enter the length and breadth of the triangle" << std::endl;
    std::cin >> one >> two;

    Rectangle rec(one, two);

    std::cout << "Area of the Rectangle = " << rec.area() << "sq. unit"
              << std::endl;

    std::cout << "Enter the lenght of base and the height of triangle\n";
    std::cin >> one >> two;

    Triangle tri(one, two);

    std::cout << "Arear of Triangle = " << tri.area() << "sq. unit"
              << std::endl;
}
#include <iostream>

struct Point
{
    int x;
    int y;
    double opacity;
};

struct Point2
{
    int x = 0;
    double opacity = 1.0;
    int y = 0;
};

// due to alignment
static_assert(sizeof(Point) != sizeof(Point2));

int main(int argc, char const *argv[])
{
    std::cout << "sizeof(Point): " << sizeof(Point) << std::endl;
    std::cout << "sizeof(Point2): " << sizeof(Point2) << std::endl;

    Point pt1 {
        .x = 4,
        .y = 5,
        .opacity = 0.3
    };

    Point2 pt_default {};
    std::cout << "pt_default.y: " << pt_default.y << std::endl;
    std::cout << "pt_default.opacity: " << pt_default.opacity << std::endl;

    Point pt2 {4, 3, 1.0};

    std::cout << "pt1.y: " << pt1.y << std::endl;

    std::cout << "pt1.opacity: " << pt1.opacity << std::endl;
    std::cout.precision(5);
    std::cout << "pt2.opacity: " << pt2.opacity << std::endl;
    pt2 = pt1;
    std::cout << "pt2.opacity: " << pt2.opacity << std::endl;
    return 0;
}

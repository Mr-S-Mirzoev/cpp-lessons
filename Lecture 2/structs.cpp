#include <iostream>

struct Point
{
    int x;
    int y;
    double opacity;
};

struct Point2
{
    int x;
    double opacity;
    int y;
};

// due to alignment
static_assert(sizeof(Point) != sizeof(Point2));

int main(int argc, char const *argv[])
{
    std::cout << "sizeof(Point): " << sizeof(Point) << std::endl;
    std::cout << "sizeof(Point2): " << sizeof(Point2) << std::endl;

    Point pt1 {
        .opacity = 0.3,
        .x = 4,
        .y = 5
    };

    Point pt2 {4, 3, 1.0};

    std::cout << "pt1.y: " << pt1.y << std::endl;

    std::cout << "pt1.opacity: " << pt1.opacity << std::endl;
    std::cout.precision(5);
    std::cout << "pt2.opacity: " << pt2.opacity << std::endl;
    pt2 = pt1;
    std::cout << "pt2.opacity: " << pt2.opacity << std::endl;
    return 0;
}

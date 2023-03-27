#include "triangle.h"

Triangle::Triangle(double a, double b) : Shape(a, b) {}

double Triangle::area() { return 0.5 * side1 * side2; }
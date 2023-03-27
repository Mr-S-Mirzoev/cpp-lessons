#include "rectangle.h"

Rectangle::Rectangle(double a, double b) : Shape(a, b) {}

double Rectangle::area() { return side1 * side2; }
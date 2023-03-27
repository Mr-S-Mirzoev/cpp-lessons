#pragma once
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(double a, double b);
    double area();
};
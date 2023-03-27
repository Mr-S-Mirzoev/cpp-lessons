#pragma once
#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle(double a, double b);
    double area() override;
};
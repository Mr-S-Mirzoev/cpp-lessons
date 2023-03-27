#pragma once

class Shape
{
protected:
    double side1, side2;

public:
    Shape(double, double);
    virtual double area() = 0;
};

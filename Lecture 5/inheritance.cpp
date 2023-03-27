/*
In C++, it is possible to inherit attributes and methods from one class to
another. We group the "inheritance concept" into two categories:

derived class (child) - the class that inherits from another class
base class (parent) - the class being inherited from
To inherit from a class, use the : symbol.

In the example below, the Car class (child) inherits the attributes and methods
from the Vehicle class (parent):
*/

#include <iostream>

// Base class
class Vehicle
{
    const char* brand = "Ford";

public:
    const char* get_brand() { return brand; }
};

// Derived class
class Car : public Vehicle
{
    const char* model = "Mustang";

public:
    const char* get_model() { return model; }
};

enum class Colour
{
    RED,
    GREEN,
    BLUE,
    BLACK,
    WHITE
};

class RedCar : public Car
{
    Colour colour = Colour::RED;

public:
    const char* get_colour() const
    {
        switch (colour)
        {
        case Colour::RED:
            return "red";

        case Colour::GREEN:
            return "green";

        case Colour::BLUE:
            return "blue";

        case Colour::BLACK:
            return "black";

        default : return "white";
        }
    }
};

enum class BodyType
{
    SEDAN,
    COUPE,
    PICKUP
};

class SedanCar : public Car
{
    BodyType body = BodyType::SEDAN;

public:
    const char* get_body_type() const
    {
        switch (body)
        {
        case BodyType::SEDAN:
            return "sedan";

        case BodyType::COUPE:
            return "coupe";

        case BodyType::PICKUP:
            return "pickup";

        default:
            return "not set";
        }
    }
};

class RedSedanCar : public RedCar, public SedanCar
{
};

int main()
{
    Car my_car;
    std::cout << my_car.get_brand() << " " << my_car.get_model() << std::endl;

    // Multilevel inheritance example
    RedCar my_red_car;
    std::cout << "Red car still can access inherited methods:"
              << my_red_car.get_brand() << " " << my_red_car.get_model()
              << ". Colour: " << my_red_car.get_colour() << std::endl;

    // Multiple inheritance example
    RedSedanCar my_red_sedan;
    std::cout << "Red car still can access inherited methods:"
              << my_red_car.get_brand() << " " << my_red_car.get_model()
              << ". Colour: " << my_red_car.get_colour()
              << ". Body type: " << my_red_sedan.get_body_type() << std::endl;
    return 0;
}
#include <iostream>

class Employee
{
private:
    // Private attribute
    int salary;

public:
    // Setter
    void set_salary(int s) { salary = s; }
    // Getter
    int get_salary() { return salary; }
};

int main()
{
    /*
    To access a private attribute, use public "get" and "set" methods:

    The salary attribute is `private`, which have restricted access.
    The public `set_salary()` method takes a parameter (s) and assigns it to the
    salary attribute (salary = s). The public `get_salary()` method returns the
    value of the private salary attribute.

    It is considered good practice to declare your class attributes (especially
    implementation related) as `private` (as often as you can). Encapsulation
    ensures better control of your data, because you (or others) can change one
    part of the code without affecting other parts, which ensures increased
    security of data.
    */
    Employee myObj;
    myObj.set_salary(50000);
    std::cout << myObj.get_salary() << std::endl;
    return 0;
}
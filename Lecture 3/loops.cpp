#include <iostream>

int main(int argc, char const *argv[])
{
    int a = 10;

    // while loop execution
    while (a < 20)
    {
        std::cout << "value of a: " << a << std::endl;
        ++a;
    }

    int b = 10;
    // do loop execution
    do
    {
        std::cout << "value of b: " << b << std::endl;
        b = b + 1;
    } while (b < 20);


    // for loop execution
    for (int c = 10; c < 20; ++c)
        std::cout << "value of c: " << c << std::endl;
    return 0;
}
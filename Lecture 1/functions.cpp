#include <iostream>

void print(int u)
{
    std::cout << "Value of u: " << u << std::endl;
}

unsigned factorial(unsigned i)
{
    // Here we used ternary operator
    return i <= 1 ? 1 : factorial(i - 1) * i;

    /*
    Now, that could have been writen with if-else statement:
    ```cpp
    if (i <= 1)
    {
        return 1;
    }
    else
    {
        return factorial(i - 1) * i;
    }
    ```

    Here are the main differences between ternary operators and if-else blocks: 
    1) A ternary operator is a single statement, while an if-else is a block of code. 
    2) A ternary operator is faster than an if-else block. Ternary operators can be used 
    in places where if-else blocks are not allowed.
    */
}

int main(int argc, char const *argv[])
{
    unsigned u;
    // print(argc);
    std::cout << "Enter u: ";
    std::cin >> u;

    // For 14 <= 33 will overflow and show wrong values, for 34 and on will return 0
    // Can overcome with https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html
    std::cout << "factorial(" << u << "): " << factorial(u) << std::endl;
    return 0;
}

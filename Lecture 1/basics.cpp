#include <climits>

constexpr unsigned factorial(unsigned i)
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
    1) A ternary operator is a single statement, while an if-else is a block of
    code. 2) A ternary operator is faster than an if-else block. Ternary
    operators can be used in places where if-else blocks are not allowed.
    */
}

const unsigned FACTORIAL_4 = factorial(4);

int main(int argc, char const* argv[])
{
    char c = 'a'; // char is always 1 byte, usually used to store human-readable
                  // characters in some encoding
    char c_data{5};

    unsigned char x = 255;

    bool flag = true; // false;

    // short; // 16 bits
    // unsigned;
    // signed; // can be omitted (default)
    // long; // always 32 bits
    // long long; // always 64 bits

    int i; // default assigned to 0
    const int INT_SIZE = sizeof(int);

    // Real - valued types

    float f = 2.f;
    const int FLOAT_SIZE = sizeof(float);

    double d = .1;
    const int DOUBLE_SIZE = sizeof(double);

    /*
    For const string literals `const char *` can be used
    UTF-8 is the default source encoding with most modern compilers.
    [Source:
    https://stackoverflow.com/questions/9739070/char-encoding#:~:text=UTF%2D8%20is%20the%20default%20source%20encoding%20with%20most%20modern%20compilers.
    */
    const char* hello{"Hello, world!"};

    // Unicode symbols can also be used, as of C++11. [Platform-dependant]
    // const char *gbp = u8"£";

    return 0;
}

#include <iostream>

int main(int argc, char const *argv[])
{
    // Dynamic Memory in C++

    // Management of dynamic memory in C++ is quite similar to C in most respects.
    // Although the library functions are likely to be available, C++ has two
    // additional operators – new and delete – which enable code to be written more clearly,
    // succinctly and flexibly, with less likelihood of errors. The new operator can be used in three ways:

    // auto *p_var = new typename;
    // auto *p_var = new type(initializer);
    // auto *p_array = new type [size];

    // In the first two cases, space for a single object is allocated; the second one includes initialization.
    // The third case is the mechanism for allocating space for an array of objects.

    int *p_var = new int;
    if (p_var)
        std::cout << "*p_var: " << *p_var << std::endl;
    p_var = new int(10);
    if (p_var)
        std::cout << "*p_var: " << *p_var << std::endl;

    int *p_array = new int [10];
    if (p_array)
    {
        // for (auto &x : p_array)
        //     std::cout << x << " ";

        for (int i = 0; i < 10; ++i)
            std::cout << p_array[i] << " ";

        std::cout << std::endl;
    }

    // The delete operator can be invoked in two ways:
    delete p_var;
    delete[] p_array;

    // The first is for a single object; the second deallocates the space used by an array.
    // It is very important to use the correct de-allocator in each case.

    // There is no operator that provides the functionality of the C realloc() function.
    // `realloc` increases or decreases the size of the specified block of memory, moving it if necessary
    // Thus even though it's a useful technique it's not available in C++ for safety reasons.

    // Here is the code to dynamically allocate an array and initialize the fourth element:
    int* pointer;
    pointer = new int[10];
    pointer[3] = 99;

    // Using the array access notation is natural. De-allocation is performed thus:
    delete[] pointer;
    pointer = nullptr;

    // Again, assigning nullptr to the pointer after deallocation is just good programming practice.
    // Another option for managing dynamic memory in C++ is the use the Standard Template Library.
    // This may be inadvisable for real time embedded systems.
    return 0;
}

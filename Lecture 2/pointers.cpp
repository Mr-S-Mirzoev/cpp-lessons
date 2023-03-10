// Pointers, Arrays, and Loops

#include <iostream>

void print()
{
    // The first range-for-statement can be read as "for every element of v,
    // from the first to the last, place a copy in x and print it." Note that we
    // don’t have to specify an array bound when we initialize it with a list.
    // The range-for-statement can be used for any sequence of elements.

    // int v[10]. Size is implicitely calculated during compilation
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for (auto x : v) // for each x in v
        std::cout << x << std::endl;
    for (auto x : {10,21,32,43,54,65})
        std::cout << x << std::endl;
}

// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
int count_x(const char* p, char x)
{
    if (p == nullptr)
        return 0;

    int count = 0;
    for (; *p != 0; ++p)
        if (*p == x)
            ++count;

    return count;
}

int main(int argc, char const *argv[])
{
    // An array of elements of type char can be declared like this:
    char v_[6]; // array of 6 characters

    // Similarly, a pointer can be declared like this:
    int* pt_; // pointer to character

    {
        int a = 4;
        pt_ = &a;
        *pt_ = 3;
        std::cout << "a: " << a << std::endl;
    }

    // In declarations, [] means "array of" and * means "pointer to."
    // All arrays have 0 as their lower bound, so v has six elements, v[0] to v[5].
    // The size of an array must be a constant expression.
    // A pointer variable can hold the address of an object of the appropriate type:
    char* p = &v_[3]; // p points to v's fourth element
    char x = *p; // *p is the object that p points to

    // In an expression, prefix unary * means "contents of" and prefix unary & means
    // "address of." We can represent the result of that initialized definition graphically:

    // Consider copying ten elements from one array to another:
    int v1[10] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10]; // to become a copy of v1
    for (int i = 0; i != 10; ++i) // copy elements
        v2[i] = v1[i];

    // This for-statement can be read as "set i to zero; while i is not 10, copy the i-th
    // element and increment i." When applied to an integer variable, the increment operator,
    // ++, simply adds 1. C++ also offers a simpler for-statement, called a range-for-statement,
    // for loops that traverse a sequence in the simplest way:
    print();

    // If we didn’t want to copy the values from v into the variable x, but
    // rather just have x refer to an element, we could write:
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for (auto& x : v)
        ++x;

    // In a declaration, the unary suffix & means "reference to." A
    // reference is similar to a pointer, except that you don’t need to use a
    // prefix* to access the value referred to by the reference. Also, a
    // reference cannot be made to refer to a different object after its
    // initialization. When used in declarations, operators (such as &,
    // *, and []) are called declarator operators:

    using T = int;

    T a_[5]; // T[5]: array of 5 Ts
    T* ptr_; // T*: pointer to T
    T& ref_ = a_[1]; // T&: reference to T. Cannot be uninitialized upon declaration.

    // We try to ensure that a pointer always points to an object, so that
    // dereferencing it is valid. When we don’t have an object to point to or
    // if we need to represent the notion of “no object available” (e.g., for
    // an end of a list), we give the pointer the value nullptr (“the null
    // pointer”). There is only one nullptr shared by all pointer types.

    // It is often wise to check that a pointer argument that is supposed to
    // point to something, actually points to something:
    std::cout << "NO of occ of 'a' in \"AbraCaDabrA\" " << count_x("AbraCaDabrA", 'a') << std::endl;
    std::cout << "NO of occ of 'a' in nullptr " << count_x(nullptr, 'a') << std::endl;

    char *ptr;
    std::cout << "NO of occ of 'a' in uninitialized string " << count_x(ptr, 'a') << std::endl;

    return 0;
}

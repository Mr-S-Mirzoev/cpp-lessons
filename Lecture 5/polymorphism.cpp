#include <iostream>

/*
Polymorphism means "many forms", and it occurs when we have many classes that
are related to each other by inheritance.

Like we specified in the previous chapter; Inheritance lets us inherit
attributes and methods from another class. Polymorphism uses those methods to
perform different tasks. This allows us to perform a single action in different
ways.

For example, think of a base class called `Animal` that has a method called
`talk()`. Derived classes of `Animals` could be `Pigs`, `Cats`, `Dogs`, `Birds`
- And they also have their own implementation of an animal sound (the pig oinks,
and the cat meows, etc.):
*/

// Base class
class Animal
{
public:
    virtual void talk()
    {
        std::cout << "The animal makes a sound" << std::endl;
    }
};

// Derived class
class Pig : public Animal
{
public:
    void talk() override { std::cout << "The pig says: wee wee" << std::endl; }
};

// Derived class
class Dog final : public Animal
{
public:
    void talk() override { std::cout << "The dog says: bow wow" << std::endl; }
    void bark() { std::cout << "The dog barks" << std::endl; }
};

int main()
{
    Animal myAnimal;
    Pig myPig;
    Dog myDog;

    Animal* anotherDog = new Dog();
    anotherDog->talk();

    myAnimal.talk();
    myPig.talk();
    myDog.talk();
    return 0;
}
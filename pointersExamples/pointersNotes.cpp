#include <iostream>

int main() {
    int a = 5;
    int *b = &a; // b is a pointer to a.
    int *c = nullptr; // c is a null pointer, good practice to initialize pointers to nullptr.
    std::cout << "a: " << a << std::endl; // Prints a (5).
    std::cout << "b: " << *b << std::endl; // Prints the value of a (5).
    std::cout << "b: " << b << std::endl; // Prints the memory address of a.
    int &ref = a; // ref is a reference to a.
    std::cout << "ref: " << ref << std::endl; // Prints the value of a (5).
    std::cout << "ref: " << &ref << std::endl; // Prints the memory address of a.
    *b = 10; // Changes the value of a to 10.
    std::cout << "a: " << a << std::endl; // Prints a (10).
    std::cout << "ref: " << ref << std::endl; // Prints the value of a (10).
    return 0;
}
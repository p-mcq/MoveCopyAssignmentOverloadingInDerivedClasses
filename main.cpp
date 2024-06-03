#include <iostream>

class Base
{
private:
    int value;

public:
    Base() : value{0} { std::cout << "Base no-args constructor" << std::endl; };
    Base(int x) : value{x} { std::cout << "Base (int) overloaded constructor" << std::endl; };

    Base(const Base &rhs) : value{rhs.value} { std::cout << "Base copy constructor" << std::endl; };
    Base &operator=(Base &rhs)
    {
        std::cout << "Base copy assignment" << std::endl;
        if (this != &rhs)
        {
            value = rhs.value;
        }
        return *this;
    }

    ~Base() { std::cout << "Base destructor" << std::endl; };
};

class Derived : public Base
{
private:
    int doubledValue;

public:
    Derived() : Base{}, doubledValue{0} { std::cout << "Derived no-args constructor" << std::endl; };
    Derived(int x) : Base{x}, doubledValue{x * 2} { std::cout << "Derived (int) overloaded constructor" << std::endl; };

    Derived(const Derived &rhs) : Base(rhs), doubledValue{rhs.doubledValue} { std::cout << "Derived copy constructor" << std::endl; };
    Derived &operator=(Derived &rhs)
    {
        std::cout << "Derived copy assignment" << std::endl;
        if (this != &rhs)
        {
            Base::operator=(rhs);
            doubledValue = rhs.doubledValue;
        }
        return *this;
    }

    ~Derived() { std::cout << "Derived destructor" << std::endl; };
};

int main()
{
    Base b{100};
    Base b1{b};
    b = b1;

    // Derived d;
    Derived d{1000};
    Derived d1{d};
    d = d1;

    // std::cout << "Hello, World!" << std::endl;
    // // getch(); // needs conio.h
    // // std::cin.get();
    // // getc(stdin);
    // std::cout << "Hello, World!" << std::endl;
    return 0;
}
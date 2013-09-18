#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;

class Base
{
public:
    Base() {}
    ~Base() {}
    virtual void f() {cout << "Base::f()" << endl;}
};

class Derived : public Base
{
public:
    Derived() {}
    ~Derived() {}
    void f() {cout << "Derived::f()" << endl;}
};

int main(int argc, char const *argv[])
{
    Base base;
    Derived derived;
    cout << "typeid(base): " << typeid(base).name() << endl;
    cout << "typeid(derived): " << typeid(derived).name() << endl;

    Base *pb = new Derived;
    cout << "typeid(pb): " << typeid(pb).name() << endl;
    cout << "typeid(*pb): " << typeid(*pb).name() << endl;

    cout << "typeid(7.84): " << typeid(7.84).name() << endl
         << "typeid(int): " << typeid(int).name() << endl
         << "typeid(double): " << typeid(double).name() << endl;
    return 0;
}
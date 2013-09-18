#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual ~Base()
    {
        cout << "B::~B()" << endl;
    }
};

class Derived : public Base
{
public:
    virtual ~Derived()
    {
        cout << "D::D~()" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Base *pBase = new Derived[10];
    delete[] pBase;
    return 0;
}
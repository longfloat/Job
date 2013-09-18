#include<iostream>
using namespace std;
class B
{
public:
    int ib;
    char cb;
public:
    B(): ib(0), cb('B') {}
    virtual void f()
    {
        cout << "B::f()" << endl;
    }
    virtual void Bf()
    {
        cout << "B::Bf()" << endl;
    }
};
class B1 : virtual public B
{
public:
    int ib1;
    char cb1;
public:
    //B1(): ib1(11), cb1('1') {}
    virtual void f()
    {
        cout << "B1::f()" << endl;
    }
    virtual void f1()
    {
        cout << "B1::f1()" << endl;
    }
    virtual void Bf1()
    {
        cout << "B1::Bf1()" << endl;
    }
};

int main()
{
    B a;
    B1 b;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
}
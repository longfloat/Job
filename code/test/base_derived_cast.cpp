#include <iostream>
using std::cout;
using std::endl;

class A
{
    int m_nA;
};

class B
{
    int m_nB;
};

class C : public A, public B
{
    int m_nC;
};

int main(int argc, char const *argv[])
{
    C *pC = new C;
    // pB指向pC中的基类B部分
    B *pB = dynamic_cast<B*>(pC);
    A *pA = dynamic_cast<A*>(pC);
    cout << "pC=" << pC << endl;
    cout << "pB=" << pB << endl;
    cout << "(C*)pB=" << (C*)pB << endl;
    cout << "pC=" << pC << endl;

    if (pC == pB)
    {
        cout << "pC == pB" << endl;
    }
    else
    {
        cout << "pC != pB" << endl;
    }

    cout << "pC=" << pC << endl;
    cout << "pB=" << pB << endl;
    cout << "int(pC)=" << int(pC) << endl;
    cout << "int(pB)=" << int(pB) << endl;

    if (int(pC) == int(pB))
    {
        cout << "int(pC) == int(pB)" << endl;
    }
    else
    {
        cout << "int(pC) != int(pB)" << endl;
    }

    return 0;
}
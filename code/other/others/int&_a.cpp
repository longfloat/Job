#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::boolalpha;
using std::endl;

int main()
{
    float a = 1.0f;
    cout << "(int)a: " << (int)a << endl;
    cout << "(int &)a: " << (int &)a << endl;
    cout << "( (int)a == (int &)a ): " 
        << boolalpha <<
        ( (int)a == (int &)a ) << endl;
    float b = 0.0f;
    cout << "(int)b: " << (int)b << endl;
    cout << "(int &)b" << (int &)b << endl;
    cout << "( (int)b == (int &)b ): "
        << boolalpha <<
        ( (int)b == (int &)b ) << endl;
    return 0;
}
#include <iostream>
using std::cout;
using std::endl;

extern int i;
int main(int argc, char const *argv[])
{
    i = 100;
    cout << i << endl;
    return 0;
}
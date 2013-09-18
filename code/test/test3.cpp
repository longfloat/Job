#include <iostream>
#include <iomanip>
#include <cstring>
using std::cout;
using std::endl;
using std::left;
using std::setfill;
using std::setw;

int main(int argc, char const *argv[])
{
    int s[] = {123, 234};
    cout << left << setfill('*') << setw(6);
    for (int i = 0; i < 2; ++i)
    {
        cout << s[i] << endl;
    }

    // char p[] = "\\0211\"xab\0";
    // cout << "p: " << p << endl;
    // cout << "strlen(p)=" << strlen(p) << endl;
    return 0;
}
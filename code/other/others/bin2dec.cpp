#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int bin2dec(int binary)
{
    if (binary < 0)
    {
        return 0;
    }

    int index = -1;
    int dec = 0;
    while (binary != 0)
    {
        ++index;
        int digital = binary % 10;
        dec += digital * (1 << index);
        binary /= 10;
    }

    return dec;
}

int main(int argc, const char *argv[])
{
    freopen("bin2dec.in", "r", stdin);
    int binary = 0;
    while (cin >> binary)
        cout << bin2dec(binary) << endl;

    fclose(stdin);
    return 0;
}
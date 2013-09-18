#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

long long get_steps(int x, int y)
{
    if (x == 0 && y == 0)
        return 0;

    if (x*y==0 && (x+y) != 0)
        return 1;

    return get_steps(x, y-1) + get_steps(x-1, y);
}

int main(int argc, char const *argv[])
{
    freopen("08.in", "r", stdin);
    int x, y;
    while (cin >> x >> y)
    {
        cout << x << "x" << y << ":\t";
        cout << get_steps(x, y) << endl;
    }

    fclose(stdin);
    return 0;
}
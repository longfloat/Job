#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

typedef unsigned int (*fun)(unsigned int);
fun f[2];

unsigned int sum1(unsigned int n)
{
    return 0;
}

unsigned int sum2(unsigned int n)
{
    return (n + f[!!n](n - 1));
}

unsigned int get_sum(unsigned int n)
{
    f[0] = sum1;
    f[1] = sum2;
    return f[!!n](n);
}


int main(int argc, char const *argv[])
{
    freopen("sum_of_n.in", "r", stdin);
    int n = 0;
    while (cin >> n)
    {
        cout << get_sum(nk) << endl;
    }
    fclose(stdin);
    return 0;
}
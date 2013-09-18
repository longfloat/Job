#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

int get_number_of_one_single(int n)
{
    int num = 0;
    while (n != 0)
    {
        if (n % 10 == 1)
        {
            ++num;
        }

        n = n / 10;
    }

    return num;
}

int get_number_of_one(int n)
{
    int num = 0;
    for (int i = 1; i <= n; ++i)
    {
        num += get_number_of_one_single(i);
    }

    return num;
}

int main(int argc, char const *argv[])
{
    freopen("num_of_one.in", "r", stdin);
    int m, n;
    while (cin >> m >> n)
    {
        if (m > n)
        {
            n = n + m;
            m = n - m;
            n = n - m;
        }
        int num_n = get_number_of_one(n);
        int num_m = get_number_of_one(m-1);

        cout << num_n - num_m << endl;
    }
    fclose(stdin);
    return 0;
}
/**
* 把只包含因子2,3,5的数称为丑数.
* 给定一个数index, 求从小到大的顺序的第index个丑数.
* 一般把1当作第一个丑数.
*/
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

bool is_ugly_number(int number)
{
    if (number <= 0)
    {
        return false;
    }

    while (number % 2 == 0)
    {
        number = number / 2;
    }

    while (number % 3 == 0)
    {
        number = number / 3;
    }

    while (number % 5 == 0)
    {
        number  = number / 5;
    }

    return ((1 == number) ? true : false);
}

int get_ugly_number(int index)
{
    if (index <= 0)
    {
        return 0;
    }

    int count = 0;
    int n = 0;
    while (count < index)
    {
        ++n;
        if (is_ugly_number(n))
        {
            ++count;
        }
    }

    return n;
}

int main(int argc, char const *argv[])
{
    freopen("ugly_number.in", "r", stdin);
    int index = 0;
    while (cin >> index)
    {
        cout << get_ugly_number(index) << endl;
    }

    fclose(stdin);
    return 0;
}
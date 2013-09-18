/**
* 把只包含因子2,3,5的数称为丑数.
* 给定一个数index, 求从小到大的顺序的第index个丑数.
* 一般把1当作第一个丑数.
*/
#include <iostream>
#include <vector>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int get_min(int a, int b, int c)
{
    int min = (a < b) ? a : b;
    min = (min < c) ? min : c;

    return min;
}

int get_ugly_number(int index)
{
    if (index <= 0)
    {
        return 0;
    }

    vector<int> iv(index);
    iv[0] = 1;
    int index2 = 0;
    int index3 = 0;
    int index5 = 0;

    int count = 1;
    while (count < index)
    {
        int min_number = get_min(iv[index2]*2, iv[index3]*3, iv[index5]*5);
        iv[count] = min_number;

        while (iv[index2]*2 <= min_number)
            ++index2;

        while (iv[index3]*3 <= min_number)
            ++index3;

        while (iv[index5]*5 <= min_number)
            ++index5;

        ++count;
    }

    return iv[index - 1];
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

/**
* 输入一串数，以','分隔，输出所有数中去掉最大值、最小值之后剩下的个数。
* （其中最大值与最小值可能有多个）
* Smple input：3,3,5,3,6,9,7,9
* Sample outPut: 3
**/
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

int num(int *data, int n)
{
    if (NULL == data || n < 0)
        return -1;

    int max = data[0], min = data[0];
    int count_max = 1, count_min = 1;

    for (int i = 1; i < n; ++i)
    {
        if (data[i] == max)
        {
            ++count_max;
			if (data[i] == min)
				++count_min;
        }
        else if (data[i] == min)
        {
            ++count_min;
			if(data[i] == max)
				++count_max;
        }
        else if (data[i] > max)
        {
            max = data[i];
            count_max = 1;
        }
        else if (data[i] < min)
        {
            min = data[i];
            count_min = 1;
        }
    }

    return (n - count_max - count_min);
}

int main(int argc, char const *argv[])
{
    freopen("number.in", "r", stdin);

    int number;
    int *data = new int[1024];
    int len = 0;
    while (cin >> number)
    {
        data[len] = number;
        cin.get();
        ++len;
    }

    cout << endl << num(data, len) << endl;
	delete[] data;

    fclose(stdin);
    return 0;
}
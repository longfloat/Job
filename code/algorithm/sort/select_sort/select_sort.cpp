#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void select_sort(int *data, int len)
{
    for (int i = 0; i < len; ++i)
    {
        // index记录最小元素下标
        int index = i;
        for (int j = i+1; j < len; ++j)
            if (data[j] < data[index])
                index = j;

        if (index != i)
            swap(data[i], data[index]);
    }
}

void print(int *data, int len)
{
    for (int i = 0; i < len; ++i)
        cout << data[i] << " ";

    cout << endl;
}

int main(int argc, char const *argv[])
{
    freopen("..\\sort.in", "r", stdin);
    int n;
    while (cin >> n)
    {
        int *data = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> data[i];

        cout << "orig:\t";
        print(data, n);
        select_sort(data, n);
        cout << "sort:\t";
        print(data, n);
        cout << "---------------------------" << endl;
        delete[] data;
    }

    fclose(stdin);
    return 0;
}
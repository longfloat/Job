#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

void insert_sort(int *data, int len)
{
    if (NULL==data || len<0)
        return;

    for (int i = 1; i < len; ++i)
    {
        int tmp = data[i];
        int j = i - 1;
        for (; j >= 0; --j)
        {
            if (data[j] > tmp)
                data[j+1] = data[j];
            else
                break;
        }

        data[j+1] = tmp;
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
        insert_sort(data, n);
        cout << "sort:\t";
        print(data, n);
        cout << "---------------------------" << endl;
        delete[] data;
    }

    fclose(stdin);
    return 0;
}
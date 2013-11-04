#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

void print_snake(int n)
{
    if (n < 0)
        return;

    int *array = new int[n*n];
    int key = 1;
    for (int m = 0; m <= 2*n-1; ++m)
    {
        if (m < n)
        {
            if (m & 1 != 0)
                for (int i = 0; i <= m; ++i)
                    *(array + i*n + (m-i)) = key++;
            else
                for (int j = 0; j <= m; ++j)
                    *(array + n*(m-j) + j) = key++;
        }
        else
        {
            if (m & 1 != 0)
                for (int i = m-(n-1); i < n; ++i)
                    *(array + i*n + (m-i)) = key++;
            else
                for (int j = m-(n-1); j < n; ++j)
                    *(array + n*(m-j) + j) = key++;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << *(array + i*n + j) << "\t";
        cout << endl;
    }

    delete[] array;
    array = NULL;
}

int main(int argc, char const *argv[])
{
    freopen("snake_array.in", "r", stdin);
    int n;
    while (cin >> n)
    {
        cout << "n = " << n << ":" << endl;
        print_snake(n);
        cout << endl;
    }
    fclose(stdin);
    return 0;
}
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

void reverse(int *start, int *end)
{
    if (NULL==start || NULL==end)
    {
        return;
    }

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

void rotate(int *data, int m, int n)
{
    if (NULL==data || m<1 || n<0)
    {
        return;
    }

    if (n % m == 0)
    {
        return;
    }
    else
    {
        n %= m;
    }

    reverse(data, data+n-1);
    reverse(data+n, data+m-1);
    reverse(data, data+m-1);
}

int main(int argc, char const *argv[])
{
    freopen("array_rotate.in", "r", stdin);
    int m = 0, n = 0;
    while (cin >> m)
    {
        cin >> n;
        int *data = new int[m];
        for (int i = 0; i < m; ++i)
        {
            cin >> data[i];
        }
        rotate(data, m, n);

        for (int i = 0; i < m; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
        delete[] data;
    }
    fclose(stdin);
    return 0;
}
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void print_array(int n)
{
    if (n < 0)
    {
        return;
    }

    if (1 == n)
    {
        cout << 1 << endl;
    }

    int a[n][n];

    int i = 0, j = 0;

    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j)
            a[i][j] = 0;

    a[0][0] = 1;
    // 计算对角线上的数字
    for (i=1; i<n; ++i)
    {
        a[i][i] = a[i-1][i-1] + i*2;
    }

    // 矩阵上半部分
    for (j=1; j<n; ++j)
    {
        for (i=j; i>0; --i)
        {
            // 根据列的奇偶性加1或减1
            a[i-1][j] = ((j%2==0) ? (a[i][j] + 1) : (a[i][j] - 1));
        }
    }

    // 矩阵下半部分
    for (i=1; i<n; ++i)
    {
        for (j=i; j>0; --j)
        {
            // 根据行的奇偶性加1或减1
            a[i][j-1] = ((i%2==0) ? (a[i][j] - 1) : (a[i][j] + 1));
        }
    }

    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

int main(int argc, const char *argv[])
{
    int n = 0;
    cout << "input n: ";
    while (cin >> n)
    {
        print_array(n);
        cout << "-----------------" << endl;
        cout << "input n: ";
    }
    return 0;
}
// 腾讯2012年实习生笔试加分题
//http://blog.csdn.net/morewindows/article/details/8742666
#include <iostream>
using std::cout;
using std::endl;

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << endl;
}
int main()
{
    const int MAXN = 5;
    int a[MAXN] = {1, 3, 5, 7, 9};
    int b[MAXN];

    cout << "a: ";
    print_array(a, MAXN);

    b[0] = 1;
    for (int i = 1; i < MAXN; i++)
        b[i] = b[i - 1] * a[i - 1];
    //int temp = 1;
    for (int i = MAXN - 1; i >= 1; i--)
    {
        // temp *= a[i + 1];
        // b[i] *= temp;
        b[i] *= b[0];
        b[0] *= a[i];
    }

    cout << "b: ";
    print_array(b, MAXN);
    return 0;
}
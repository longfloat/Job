#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

static int count = 0;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *a, int length, int start, int end)
{
    int index = start + rand() % (end-start+1);
    swap(a[index], a[end]);

    int small = start - 1;
    for (index = start; index < end; ++index)
    {
        if (a[index] < a[end])
        {
            ++small;
            if (small != index)
            {
                swap(a[small], a[index]);
            }
        }
    }

    ++small;
    swap(a[small], a[end]);
    return small;
}

void get_k_min(int *orig, int n, int k, int *result)
{
    if (NULL==orig || NULL==result || n<k || n<0 || k<0)
    {
        return;
    }
    int start = 0;
    int end = n - 1;

    int index = partition(orig, n, start, end);

    while (index != k-1)
    {
        if (index > k-1)
        {
            end = index - 1;
            index = partition(orig, n, start, end);
        }
        else
        {
            start = index + 1;
            index = partition(orig, n, start, end);
        }
    }

    for (int i = 0; i < k; ++i)
    {
        result[i] = orig[i];
    }
}

void print_arr(int *a, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    freopen("k_min.in", "r", stdin);

    int n = 0, k = 0;
    while (cin >> n >> k)
    {
        int *a = new int[n];
        int *result = new int[k];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        get_k_min(a, n, k, result);
        print_arr(result, k);
        delete[] a;
        delete[] result;
    }
    fclose(stdin);
    return 0;
}
#include <set>
#include <iostream>
#include <cstdio>
using std::multiset;
using std::cin;
using std::cout;
using std::endl;

void get_k_min(int *a, int length, int k, multiset<int> &ims)
{
    for (int i = 0; i < length; ++i)
    {
        if (ims.size() < k)
        {
            ims.insert(a[i]);
        }
        else
        {
            multiset<int>::iterator ims_iter = ims.end();
            int max = *(--ims_iter);

            if (a[i] < max)
            {
                ims.erase(ims_iter);
                ims.insert(a[i]);
            }
        }
    }
}

void print_multiset(multiset<int> &ims)
{
    for (multiset<int>::iterator iter = ims.begin(); iter != ims.end(); ++iter)
    {
        ++iter;
        if (iter != ims.end())
        {
            --iter;
            cout << *iter << " ";
        }
        else
        {
            --iter;
            cout << *iter;
        }
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
        multiset<int> ims;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        get_k_min(a, n, k, ims);
        print_multiset(ims);
        delete[] a;
    }

    fclose(stdin);
    return 0;
}
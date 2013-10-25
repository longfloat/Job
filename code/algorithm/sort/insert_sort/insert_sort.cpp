#include <iostream>
#include <vector>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;


template <typename T>
void insert_sort(vector<T> &data)
{
    if (data.empty())
        return;

    for (int i = 1; i < data.size(); ++i)
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

template <typename T>
void print_vector(vector<T> &v)
{
    for (typename vector<T>::iterator iter = v.begin(); iter != v.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    freopen("..\\sort.in", "r", stdin);
    int n;
    while (cin >> n)
    {
        vector<int> iv(n);
        for (int i = 0; i < n; ++i)
            cin >> iv[i];

        cout << "orig:\t";
        print_vector(iv);
        insert_sort(iv);
        cout << "sort:\t";
        print_vector(iv);
        cout << "---------------------------" << endl;
    }

    fclose(stdin);
    return 0;
}
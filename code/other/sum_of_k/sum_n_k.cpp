#include <list>
#include <iostream>
using std::list;
using std::cout;
using std::endl;

void get_comb(int *a, int index, int length, int sum, list<int> &list_int)
{
    if (index<0 || index>=length || length<=0)
    {
        return;
    }

    if (sum == a[index])
    {
        for (list<int>::iterator iter=list_int.begin(); iter!=list_int.end(); ++iter)
        {
            cout << *iter << "+";
        }
        cout << a[index] << endl;
    }

    list_int.push_back(a[index]);
    get_comb(a, index+1, length-index, sum-a[index], list_int);
    list_int.pop_back();
    get_comb(a, index+1, length-index, sum, list_int);
}

void combination(int *a, int length, int sum)
{
    for (int i = 0; i < length; ++i)
    {
        list<int> list_int;
        get_comb(a, i, length-i, sum, list_int);
    }
}

int main(int argc, char const *argv[])
{
    int length = 6;
    int a[] = {4, 3, 2, 2, 1, 1};
    int sum = 4;
    //combination(a, ARRAY_LENGTH, sum);
    combination(a, length, sum);
    return 0;
}
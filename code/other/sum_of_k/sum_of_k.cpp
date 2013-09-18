#include <iostream>
#include <vector>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int get_sum(const vector<int> &iv)
{
    int sum = 0;
    for (vector<int>::const_iterator citer=iv.begin(); citer!=iv.end(); ++citer)
        sum += *citer;

    return sum;
}

void get_sum_of_k(const vector<int> &data, size_t index, int sum, vector<int> &result, const int base_sum)
{
    if (data.size()<1 || index<0 || index>data.size() || sum<0)
    {
        return;
    }

    if (0 == sum)
    {
        vector<int>::const_iterator citer = result.begin();
        for ( ; citer!=result.end()-1; ++citer)
        {
            cout << *citer << " + ";
        }
        cout << *citer << " = " << base_sum << endl;
        return;
    }

    for (size_t i = index; i < data.size(); ++i)
    {
        result.push_back(data[i]);
        get_sum_of_k(data, i+1, sum-data[i], result, base_sum);
        result.pop_back();
    }
}

int main(int argc, const char *argv[])
{
    freopen("sum_of_k.in", "r", stdin);
    int n = 0, sum = 0;
    while (cin >> n)
    {
        cin >> sum;
        vector<int> iv;
        int ele = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> ele;
            iv.push_back(ele);
        }

        vector<int> result;
        get_sum_of_k(iv, 0, sum, result, sum);
        cout << "-------------------" << endl;
    }
    fclose(stdin);
    return 0;
}

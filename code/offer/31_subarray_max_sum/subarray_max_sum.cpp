#include <iostream>
#include <vector>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int get_subarray_max_sum(vector<int> &iv, vector<int> &iv_max)
{
    if (iv.empty())
    {
        return -1;
    }

    vector<int>::iterator beg=iv.begin(), end=iv.begin(), cur=iv.begin();
    int sum = *(iv.begin()), max_sum = sum;

    for (vector<int>::iterator iter=iv.begin()+1; iter!=iv.end(); ++iter)
    {
        if (sum > 0)
        {
            sum += *iter;
        }
        else
        {
            sum = *iter;
            cur = iter;
        }

        if (sum > max_sum)
        {
            max_sum = sum;
            beg = cur;
            end = iter;
        }
    }

    while (beg != end+1)
    {
        iv_max.push_back(*beg);
        ++beg;
    }

    return max_sum;
}

void print_vector(vector<int> &iv)
{
    for (vector<int>::iterator iter=iv.begin(); iter!=iv.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    freopen("subarray_max_sum.in", "r", stdin);
    int num = 0;
    while (cin >> num)
    {
        cout << "--------------------------" << endl;
        if (num > 0)
        {
            vector<int> iv;
            int data;
            for (int i = 0; i < num; ++i)
            {
                cin >> data;
                iv.push_back(data);
            }

            vector<int> iv_max;
            int max_sum = get_subarray_max_sum(iv, iv_max);
            cout << "the array: ";
            print_vector(iv);
            cout << "the subarray with max sum: ";
            print_vector(iv_max);
            cout << "max sum of the subarray: " << max_sum << endl;
        }
        else if (0 == num)
        {
            cout << "empty array!" << endl;
        }
        else
        {
            cout << "invalid input!" << endl;
        }
    }

    fclose(stdin);
    return 0;
}
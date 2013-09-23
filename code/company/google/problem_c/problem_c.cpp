#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool is_even(int n)
{
    return ((n & 1) == 0);
}

bool compare_alex(const int &i, const int &j)
{
    return i < j;
}

bool compare_bob(const int &i, const int &j)
{
    return i > j;
}

void print_all(vector<int> &iv)
{
    for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cout << "small(0) or large(1): ";
    int type;
    cin >> type;
    if (0 == type)
    {
        freopen("C-small-practice.in", "r", stdin);
        freopen("C-small-practice.out", "w", stdout);
    }
    else if (1 == type)
    {
        freopen("C-large-practice.in", "r", stdin);
        freopen("C-large-practice.out", "w", stdout);
    }
    else
    {
        cout << "invalid input!!!" << endl;
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        int worth;
        vector<int> alex;   // odd
        vector<int> bob;    // even
        vector<bool> order;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            cin >> worth;
            if (is_even(worth))
            {
                bob.push_back(worth);
                order.push_back(true);
            }
            else
            {
                alex.push_back(worth);
                order.push_back(false);
            }
        }

        std::sort(alex.begin(), alex.end(), compare_alex);
        std::sort(bob.begin(), bob.end(), compare_bob);

        vector<int> all_worths;
        vector<int>::iterator alex_iter = alex.begin();
        vector<int>::iterator bob_iter = bob.begin();
        for (vector<bool>::iterator iter = order.begin(); iter != order.end(); ++iter)
        {
            if (*iter)
            {
                all_worths.push_back(*bob_iter);
                ++bob_iter;
            }
            else
            {
                all_worths.push_back(*alex_iter);
                ++alex_iter;
            }
        }

        cout << "Case #" << i+1 << ": ";
        print_all(all_worths);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
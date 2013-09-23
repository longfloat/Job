#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct range
{
    int start;
    int end;
    range(int _start=0, int _end=0) : start(_start), end(_end)
    {}

    bool operator<(const range &rhs)
    {
        if (start <= rhs.start)
            return true;
        else
            return false;
    }
};

bool compare(range lhs, range rhs)
{
    return lhs < rhs;
}

bool check_range(vector<range> &invs)
{
    if (invs.empty())
        return false;

    std::sort(invs.begin(), invs.end(), compare);
    for (vector<range>::iterator iter_i = invs.begin(); iter_i != invs.end(); ++iter_i)
    {
        for (vector<range>::iterator iter_j = iter_i + 1; iter_j != invs.end(); ++iter_j)
        {
            if (iter_j->end < iter_i->end)
            {
                return true;
            }
        }
    }

    return false;
}

int interval(vector < int > a)
{
    vector<range> invs;
    for (int i = 0; i < a.size(); i+=2)
    {
        range r(a[i], a[i+1]);
        invs.push_back(r);
    }

    return check_range(invs);
}

int main(int argc, const char *argv[])
{
    freopen("check_interval.in", "r", stdin);
    int n;
    while (cin >> n)
    {
        // vector<range> invs(n);
        // for (int i = 0; i < n; ++i)
        // {
        //     int start, end;
        //     cin >> start >> end;
        //     range iv(start, end);
        //     invs[i] = iv;
        // }

        // cout << check_range(invs) << endl;
        vector<int> iv(2*n);
        for (int i = 0; i < 2*n; ++i)
            cin >> iv[i];
        cout << interval(iv) << endl;
    }
    fclose(stdin);
}
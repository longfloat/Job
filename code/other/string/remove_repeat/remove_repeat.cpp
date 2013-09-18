/**
* 去除字符串中的重复字符
*/
#include <iostream>
#include <string>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string remove_repeat(const string &s)
{
    if (s.length() == 0)
    {
        return s;
    }

    int flag[256] = {0};
    for (int i = 0; i < s.length(); ++i)
    {
        ++flag[s[i]];
    }

    string tmp;
    for (int i = 0; i < s.length(); ++i)
    {
        if (flag[s[i]] >= 1)
        {
            tmp.push_back(s[i]);
            flag[s[i]] = 0;
        }
    }

    return tmp;
}

int main(int argc, const char *argv[])
{
    freopen("remove_repeat.in", "r", stdin);
    string str;
    while (cin >> str)
    {
        cout << remove_repeat(str) << endl;
    }
    fclose(stdin);
    return 0;
}
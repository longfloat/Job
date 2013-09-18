#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int CHAR_NUM = 256;
int flag[CHAR_NUM] = {0};

void reset_flags()
{
    memset(flag, 0, sizeof(flag));
    // 确保能够扫描到子串的最后一个字符是源串末尾的情况
    flag['\0'] = 1;
}

string longest_norepeat_substring(const string &s)
{
    if (s.length() == 0)
    {
        return "";
    }

    string longest = s.substr(0, 1);
    for (size_t i = 0; i < s.length(); ++i)
    {
        size_t p = i;
        while(p <= s.length())
        {
            if (flag[static_cast<size_t>(s[p])] == 0)
            {
                flag[static_cast<size_t>(s[p])] = 1;
                ++p;
            }
            else
            {
                string s1 = s.substr(i, p - i);
                if (s1.length() > longest.length())
                {
                    longest = s1;
                }
                reset_flags();
                break;
            }
        }
    }

    return longest;
}

int main(int argc, const char *argv[])
{
    freopen("longest_norepeat_substring.in", "r", stdin);
    string s;
    while (cin >> s)
    {
        cout << longest_norepeat_substring(s) << endl;
    }
    fclose(stdin);
    return 0;
}

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int CHAR_NUM = 256;
int visit[CHAR_NUM] = {-1};

string longest_norepeat_substring(const string &s)
{
    if (s.length() == 0)
    {
        return "";
    }
    memset(visit, -1, sizeof(visit));

    int longest_index = 0, longest_len = 0;
    int current_len = 1, last_start = 0;
    visit[s[0]] = 0;

    for (size_t i = 1; i < s.length(); ++i)
    {
        if (visit[s[i]] == -1)
        {
            ++current_len;
        }
        else
        {
            if (last_start <= visit[s[i]])
            {
                last_start = visit[s[i]] + 1;
                current_len = i - visit[s[i]];
            }
            else
            {
                ++current_len;
            }
        }
        visit[s[i]] = i;
        if (current_len > longest_len)
        {
            longest_len = current_len;
            longest_index = i - longest_len + 1;
        }
    }

    return s.substr(longest_index, longest_len);
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
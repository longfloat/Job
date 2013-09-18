#include <string>
#include <cmath>
#include <iostream>
#include <cstdio>
using std::string;
using std::cin;
using std::cout;
using std::endl;

const int d = 256;
const int PRIME = 127;

void rabin_karp_matcher(const string& text, const string& pattern, int q)
{
    if (text.length()<1 || pattern.length()<1 || text.length()<pattern.length() || q<0)
    {
        //return -1;
        cout << "invalid input!" << endl;
        return;
    }

    int n = text.length();
    int m = pattern.length();
    int h = 1;
    for (int i=0; i<m-1; ++i)
    {
        h = (h*d) % q;
    }
    int p = 0;
    int t = 0;

    for (int i = 0; i < m; ++i)
    {
        p = (d*p + pattern[i]) % q;
        t = (d*t + text[i]) % q;
    }

    for (int s = 0; s < n-m+1; ++s)
    {
        if (p == t)
        {
            int j = 0;
            for (j = 0; j<m && pattern[j]==text[s+j]; ++j)
            {}

            if (j==m)
            {
                cout << s << " ";
            }
        }

        if (s < n-m)
        {
            t = (d*(t - h*text[s]) + text[s+m]) % q;
            if (t < 0)
                t += q;
        }
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    freopen("../string_matcher.in", "r", stdin);
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string text("");
        string pattern("");
        cin >> text;
        cin >> pattern;
        rabin_karp_matcher(text, pattern, PRIME);
    }
    fclose(stdin);
    return 0;
}

#include <iostream>
#include <string>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void naive_string_matcher(const string& text, const string& pattern)
{
    if (text.size()<1 || pattern.size()<1 || text.size()<pattern.size())
    {
        cout << "invalid input!" << endl;
        return;
    }

    int len = text.size() - pattern.size() + 1;
    for (int s = 0; s < len; ++s)
    {
        int p = 0;
        while (p<pattern.size() && text[s+p]==pattern[p])
        {
            ++p;
        }

        if (p == pattern.size())
        {
            cout << s << " ";
        }
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    freopen("../string_matcher.in", "r", stdin);
    // cout << __FILE__ << endl;
    // cout << __LINE__ << endl;
    int n = 0;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; ++i)
    {
        string text("");
        string pattern("");
        getline(cin, text);
        //cout << text << endl;
        getline(cin, pattern);
        //cout << pattern << endl;
        naive_string_matcher(text, pattern);
    }
    fclose(stdin);
    return 0;
}
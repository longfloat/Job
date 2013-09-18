#include <iostream>
#include <vector>
#include <cstring>
#include <cstddef>
using std::cout;
using std::endl;
using std::vector;

void combination(char *str, size_t m, vector<char> &cv)
{
    if (NULL==str || ((*str)=='\0' && m!=0))
    {
        return;
    }

    if (0 == m)
    {
        for (std::vector<char>::iterator iter = cv.begin(); iter != cv.end(); ++iter)
        {
            cout << *iter;
        }
        cout << endl;
        return;
    }

    // 字符组合中包含当前字符
    cv.push_back(*str);
    combination(str+1, m-1, cv);
    cv.pop_back();
    combination(str+1, m, cv);
}

void combination(char *str)
{
    if (NULL==str || *str=='\0')
    {
        return;
    }
    size_t len = strlen(str);
    for (size_t i=1; i<=len; ++i)
    {
        vector<char> cv;
        combination(str, i, cv);
    }
}

int main(int argc, char const *argv[])
{
    char str[] = "abc";
    combination(str);
    return 0;
}
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::min;

string longest_palindrome_manacher(const string &s)
{
    // 对源串s进行扩展, 使得字符串长度变为奇数
    // 每个字符的两边插入一个特殊字符, 比如'#';
    // 在扩展后的字符串的开始插入一个标记'$', 表示字符串的开始
    // 避免越界问题的处理

    // mx是以id所指示位置字符为中心的回文字符串的半径
    int id = 0, mx = 0;
    int len = 2 * s.length() + 4;
    // 数组p存储以字符p[i]为中心的最长回文半径
    int p[len];
    memset(p, 0, sizeof(p));

    // 扩展源字符串
    string str(len, '#');
    str[0] = '$';
    for (int i = 0; i < s.length(); ++i)
    {
        str[2*i+2] = s[i];
    }

    for (int i = 0; i < str.length(); ++i)
    {
        p[i] = (mx > i) ? min(p[2*id-i], mx-i) : 1;
        // 向两侧扩展
        while (str[i+p[i]] == str[i-p[i]])
            ++p[i];

        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
    }

    // 截取最长回文子串
    string tmp(str.substr(2*id-mx, 2*(mx-id)+1));

    // 去除串中的特殊字符
    string longest;
    for (int i = 0; i < tmp.length(); ++i)
    {
        if (tmp[i] != '#')
        {
            longest.push_back(tmp[i]);
        }
    }

    return longest;
}

int main(int argc, const char *argv[])
{
    freopen("longest_palindrome.in", "r", stdin);
    string s;
    while (cin >> s)
    {
        cout << longest_palindrome_manacher(s) << endl;
    }
    fclose(stdin);
    return 0;
}
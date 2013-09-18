/**
* 局部反转一个给定字符串
* e.g. this is a test string
* 反转后: string test a is this
*/
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

void reverse_string(char str[], int start, int end)
{
    if (NULL==str || start<0 || end<0 || start>strlen(str) || end>strlen(str))
    {
        return;
    }

    while (start < end)
    {
        char ch = str[start];
        str[start] = str[end];
        str[end] = ch;
        ++start;
        --end;
    }
}

void reverse_string_local(char str[])
{
    int length = strlen(str);
    reverse_string(str, 0, length-1);
    cout << str << endl;

    int start = 0;
    while (str[start] != '\0')
    {
        int end = start;
        while ((str[end] != ' ') && (str[end] != '\0'))
        {
            ++end;
        }
        reverse_string(str, start, end-1);
        cout << str << endl;
        if (str[end] == '\0')
        {
            // 到字符串末尾了, 直接退出
            break;
        }
        start = end + 1;
    }
}

int main(int argc, char const *argv[])
{
    char str[] = "this is a test string";
    //char str[] = "this god";
    cout << "before reverse: " << str << endl;
    reverse_string_local(str);
    cout << "after reverse: " << str << endl;
    return 0;
}
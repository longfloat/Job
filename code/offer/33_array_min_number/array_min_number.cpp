/**
* 输入一个正整数数组, 把数组里所有数字拼接起来排成一个数,
* 打印能拼接出的所有数字中最小的一个.
* e.g. 输入数组{3,32,321}, 则打印出这3个数字能排成的最小数字321323.
* 
* 输入:
* 多组数据, 每组数据包含两行;
* 第一行为一个整数n, 表示数组元素个数;
* 之后的一行包含n个整数, 为数组中的n个元素
* (对于空数组, 只有一行元素, 即元素个数0,)
* 
* 输出:
* 每组数据对应一行输出, 为对应数组中能够拼接的数字中的最小的数字
* 空数组输出empty!
* 
* 分析:
* >> 对于两个数m和n, 它们可以拼成数字mn或者nm, 如果拼后的数字mn<nm,
* 那么在输出的最小数字中, m应该排在n前面.
* >> 由于两个数拼接后可能会超出整数表示的范围, 
* 因此将输入数组转化成字符串后进行处理. 
* 而对于拼接后的字符串, 由于位数相同, 故它们之间的大小关系与整数是一致的. 
* >> 因此可以通过一个特定的排序依据对转化后的字符串数组从小到大排序, 
* 然后依次输出排序后的字符串数组即得到能拼接出的所有数字中最小的一个.
*/

#include <sstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using std::ostringstream;
using std::sort;
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

/**
* 将整数转换成字符串, 利用了stringstream转换
*/
template <typename T>
string number_to_string(T number)
{
    ostringstream ss;
    ss << number;
    return ss.str();
}

bool compare(const string &s1, const string &s2)
{
    string str1(s1 + s2);
    string str2(s2 + s1);
    return (str1 < str2);
}

string get_min_number(vector<int> &iv)
{
    if (iv.empty())
    {
        return "empty!";
    }

    vector<string> sv;
    for (vector<int>::iterator iter=iv.begin(); iter!=iv.end(); ++iter)
    {
        sv.push_back(number_to_string<int>(*iter));
    }

    sort(sv.begin(), sv.end(), compare);
    string result("");
    for (vector<string>::iterator iter=sv.begin(); iter!=sv.end(); ++iter)
    {
        result += *iter;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    freopen("array_min_number.in", "r", stdin);
    int length;

    while (cin >> length)
    {
        int data = 0;
        vector<int> iv;
        for (int i = 0; i < length; ++i)
        {
            cin >> data;
            iv.push_back(data);
        }

        string min_number = get_min_number(iv);
        cout << min_number << endl;
    }

    fclose(stdin);
    return 0;
}
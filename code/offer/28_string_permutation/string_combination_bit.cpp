/**
* 使用位运算获取字符串组合
* 根据字符个数构造相应数目的01, 根据各位01的不同控制对应位置字符的输出
* e.g. 对于字符串abc, 构造三位二进制位: 000,001,010,011,100,101,110,111
* 二进制位某位为1时, 输出字符串对应位置的字符, 为0时不输出
* 如此可得到字符的所有组合
*/

#include <iostream>
#include <bitset>
#include <string>
using std::cout;
using std::endl;
using std::bitset;
using std::string;

const int CHAR_COUNT = 3;

/**
* 模拟二进制加法运算, 逢2进1
*/
bool is_increment(bitset<CHAR_COUNT> &cbs)
{
    if (CHAR_COUNT <= 0)
    {
        return false;
    }

    for (int i=CHAR_COUNT-1; i>=0; --i)
    {
        if (0 == cbs[i])
        {
            cbs[i] = 1;
            return true;
        }
        else
        {
            if (i != 0)
            {
                cbs[i] = 0;
            }
            else
            {
                // 二进制的最高位已经为1了, 不能再进行加法运算, 否则会溢出
                return false;
            }
        }
    }
}

void print_combination(const string &str, const bitset<CHAR_COUNT> &cbs)
{
    if (CHAR_COUNT <=0 || CHAR_COUNT != str.length())
    {
        return;
    }

    for (int i = 0; i < CHAR_COUNT; ++i)
    {
        if (1 == cbs[i])
        {
            cout << str[i];
        }
    }
    cout << endl;
}

void get_string_combination_bit(const string &str)
{
    bitset<CHAR_COUNT> cbs;
    while (is_increment(cbs))
    {
        print_combination(str, cbs);
    }
}

int main(int argc, char const *argv[])
{
    const string str("abc");
    get_string_combination_bit(str);
    return 0;
}
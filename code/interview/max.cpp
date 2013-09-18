#include <iostream>
using std::cout;
using std::endl;

/**
* 将一个int分成两部分,最高位为符号位,剩下的31位为负载部分;
* 符号位通过signed_bit得出(0或1);
* 负载部分通过value_stuff得出, 介于0~0x7fffffff之间,总为正数;
* value_diff对两个负载做减法运算, 返回运算结果符号位,
* 结果为0表明x负载>y负载,为1表明x负载<y负载
*/

const int BIT_SIZE = sizeof(int) * 8;
inline int signed_bit(int x)
{
    return (x & 0x80000000) >> (BIT_SIZE - 1);
}

inline int value_stuff(int x)
{
    return x & 0x7fffffff;
}

inline int value_diff(int x, int y)
{
    return signed_bit(value_stuff(x) - value_stuff(y));
}

int max(int x, int y)
{
    int nums[2][2][2] = {
        x,  // 000 x为正数, y为正数, x负载>=y负载, 则x为最大值;
        y,  // 001 x为正数, y为正数, x负载<y负载, 则y为最大值;
        x,  // 010 x为正数, y为负数, 则x为最大值(无需考虑负载);
        x,  // 011 x为正数, y为负数, 则x为最大值(无需考虑负载);
        y,  // 100 x为负数, y为正数, 则y为最大值(无需考虑负载);
        y,  // 101 x为负数, y为正数, 则y为最大值(无需考虑负载);
        x,  // 110 x为负数, y为负数, x负载>=y负载, 则x为最大值;
        y   // 111 x为负数, y为负数, x负载<y负载, 则y为最大值;
    };

    return nums[signed_bit(x)][signed_bit(y)][value_diff(x, y)];
}

int main(int argc, char const *argv[])
{
    int a = 2000000000;
    int b = -2000000000;
    cout << "BIT_SIZE=" << BIT_SIZE << endl;
    cout << "signed_bit(" << a << ")=" << signed_bit(a) << endl;
    cout << "signed_bit(" << b << ")=" << signed_bit(b) << endl;
    cout << "value_diff(" << a << "," << b << ")=" << value_diff(a, b) << endl;
    cout << a << "," << b << ": " << max(a, b) << endl; 
    return 0;
}
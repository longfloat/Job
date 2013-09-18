#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// 使用非类型模板形参接受待转换的二进制数字
// 注意模板的非类型形参必须是编译时的常量表达式
template <int bin_num>
class binary
{
public:
    static int value;
private:
    // 由于模板的非类型形参必须是编译时常量表达式
    // 故此处用一个私有静态数据成员保存该形参
    static int data;

    // 实现二进制向十进制的转换
    static int bin2dec()
    {
        if (data < 0)
        {
            return 0;
        }

        int index = -1;
        int dec = 0;
        while (data != 0)
        {
            ++index;
            int digital = data % 10;
            dec += digital * (1 << index);
            data /= 10;
        }
       
        return dec;
    }
};

// 模板静态成员的初始化
template <int bin_num> int binary<bin_num>::value = bin2dec();
template <int bin_num> int binary<bin_num>::data = bin_num;

int main(int argc, const char *argv[])
{
    cout << binary<1>::value << endl;
    cout << binary<10>::value << endl;
    cout << binary<110>::value << endl;
    cout << binary<1110>::value << endl;
    cout << binary<11110>::value << endl;
    cout << binary<111110>::value << endl;
    cout << binary<1111110>::value << endl;
    cout << binary<1010101>::value << endl;
    return 0;
}
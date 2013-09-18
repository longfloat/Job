#include <cstdlib> // atoi
#include <cstdio>
#include <cstring> // strlen
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int power_of_ten(size_t exp)
{
    int result = 1;
    for (size_t i=0; i<exp; ++i)
    {
        result *= 10;
    }

    return result;
}

int get_number_of_one_core(const char *str)
{
    if (NULL==str || *str<'0' || *str>'9' || *str=='\0')
    {
        return 0;
    }

    size_t length = static_cast<size_t>(strlen(str));
    int first_digit = *str - '0';

    // 处理一位数的情况
    if (1==length && 0==first_digit)
    {
        return 0;
    }

    if (1==length && first_digit>0)
    {
        return 1;
    }

    int num_first = 0;

    // 最高位出现1的次数
    // 1346~21345中10000~19999
    if (first_digit > 1)
    {
        num_first = power_of_ten(length - 1);
    }
    else if (1 == first_digit)
    {
        num_first = atoi(str+1) + 1;
    }

    // 除最高位之外其他位出现1的次数
    // 1346~11345 11346~21345
    // 除去最高位, 剩余四位中, 固定某一位为1, 其余三位可从0~9中选取
    int num_other = first_digit * (length-1) + power_of_ten(length-2);

    // 使用递归方式求解的1的次数
    // 1-1345
    int num_recur = get_number_of_one_core(str + 1);

    return num_first + num_other + num_recur;
}

int get_number_of_one(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    const int CHAR_COUNT = 50;

    char str[CHAR_COUNT];
    sprintf(str, "%d", n);
    return get_number_of_one_core(str);
}

int main(int argc, char const *argv[])
{
    freopen("num_of_one.in", "r", stdin);
    int m, n;
    while (cin >> m >> n)
    {
        if (m > n)
        {
            n = n + m;
            m = n - m;
            n = n - m;
        }
        int num_n = get_number_of_one(n);
        int num_m = get_number_of_one(m-1);

        cout << num_n - num_m << endl;
    }
    fclose(stdin);
    return 0;
}
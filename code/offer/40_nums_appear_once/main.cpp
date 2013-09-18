#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

size_t first_one(int num)
{
    size_t bit_index = 0;
    while (((num&1)==0) && (bit_index<8*sizeof(int)))
    {
        ++bit_index;
        num = num >> 1;
    }
    return bit_index;
}

bool is_bit_one(int num, size_t bit_index)
{
    num = num >> bit_index;
    return ((num&1) == 1);
}

void find_nums_appear_once(int *data, int length,
                            int &num1, int &num2)
{
    if (NULL == data || length < 2)
    {
        return;
    }

    int tmp = 0;
    for (int i = 0; i < length; ++i)
    {
        tmp ^= data[i];
    }

    int bit_index = first_one(tmp);
    num1 = num2 = 0;
    for (int i = 0; i < length; ++i)
    {
        if (is_bit_one(data[i], bit_index))
        {
            num1 ^= data[i];
        }
        else
        {
            num2 ^= data[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("in", "r", stdin);
    int length = 0;
    while (cin >> length)
    {
        int *data = new int[length];
        for (int i = 0; i < length; ++i)
        {
            cin >> data[i];
        }
        int num1 = 0, num2 = 0;
        find_nums_appear_once(data, length, num1, num2);
        cout << num1 << " " << num2 << endl;
    }
    fclose(stdin);
    return 0;
}
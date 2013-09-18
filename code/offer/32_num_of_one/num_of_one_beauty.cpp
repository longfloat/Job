#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

long long get_number_of_one(long long number)
{
    if (number < 1)
    {
        return 0;
    }
    long long lower_num = 0, current_num = 0, higher_num = 0;
    long long factor = 1;
    long long count = 0;
    while (number / factor != 0)
    {
        lower_num = number - (number / factor) * factor;
        current_num = (number / factor) % 10;
        higher_num = number / (factor * 10);

        switch(current_num)
        {
            case 0:
                    count += higher_num * factor;
                    break;
            case 1:
                    count += higher_num * factor + lower_num + 1;
                    break;
            default:
                    count += (higher_num + 1) * factor;
                    break;
        }

        factor *= 10;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    freopen("num_of_one.in", "r", stdin);
    long long m, n;
    while (cin >> m >> n)
    {
        if (m > n)
        {
            cout << get_number_of_one(m) - get_number_of_one(n - 1) << endl;
        }
        else
        {
            cout << get_number_of_one(n) - get_number_of_one(m - 1) << endl;
        }
    }
    fclose(stdin);
    return 0;
}
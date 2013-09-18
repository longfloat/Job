#include <iostream>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;

bool is_invalid_input = false;
const int NOT_FOUNTD = -1;

bool validate_input(int *a, int length)
{
    is_invalid_input = false;
    if (NULL == a && length <= 0)
    {
        is_invalid_input = true;
    }

    return is_invalid_input;
}

void print_arr(int *a, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

bool validate_half_more(int *a, int length, int result)
{
    int count = 0;
    for (int i = 0; i < length; ++i)
    {
        if (a[i] == result)
        {
            ++count;
        }
    }

    if (count <= (length >> 1))
    {
        is_invalid_input = true;
        return false;
    }
    else
    {
        return true;
    }
}

int get_more_than_half(int *a, int length)
{
    if (validate_input(a, length))
    {
        return 0;
    }

    int times = 1;
    int result = a[0];
    for (int i = 1; i < length; ++i)
    {
        if (0 == times)
        {
            result = a[i];
            times = 1;
        }
        else if (a[i] == result)
        {
            ++times;
        }
        else
        {
            --times;
        }
    }

    if (!validate_half_more(a, length, result))
    {
        result = 0;
    }

    return result;
}

void print_result(int result)
{
    if (0 == result)
    {
        cout << NOT_FOUNTD << endl;
    }
    else
    {
        cout << result << endl;
    }
}

int main(int argc, char const *argv[])
{
    freopen("more_than_half.in", "r", stdin);
    freopen("more_than_half2.out", "w", stdout);
    int length = 0;
    while (cin >> length)
    {
        //cout << "------------------------" << endl;
        int *array = new int[length];
        for (int i = 0; i < length; ++i)
        {
            cin >> array[i];
        }

        //cout << "the array: ";
        //print_arr(array, length);
        int result = get_more_than_half(array, length);   
        print_result(result);
        delete[] array;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
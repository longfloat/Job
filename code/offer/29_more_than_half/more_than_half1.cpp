#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

bool is_invalid_input = false;
const int NOT_FOUND = -1;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
bool validate_input(int *a, int length)
{
    is_invalid_input = false;
    if (NULL == a && length <= 0)
    {
        is_invalid_input = true;
    }

    return is_invalid_input;
}

int partition(int *a, int start, int end)
{
    int index = (rand() % (end-start+1)) + start;
    swap(a[index], a[end]);

    int small = start - 1;
    for (index = start; index < end; ++index)
    {
        if (a[index] < a[end])
        {
            ++small;
            if (small != index)
            {
                swap(a[small], a[index]);
            }
        }
    }

    ++small;
    swap(a[small], a[end]);
    return small;
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

    if ((count<<2) <= length)
    {
        is_invalid_input = true;
        return false;
    }
    else
    {
        return true;
    }
}

int get_half_more(int *a, int length)
{
    if (validate_input(a, length))
    {
        return 0;
    }
    int start = 0;
    int end  = length - 1;
    int middle = length >> 1;
    int index = partition(a, start, end);
    while (index != middle)
    {
        if (index > middle)
        {
            end = index - 1;
            index = partition(a, start, end);
        }
        else
        {
            start = index + 1;
            index = partition(a, start, end);
        }
    }

    int result = a[middle];
    if (!validate_half_more(a, length, result))
    {
        result = 0;
    }

    return result;
}

void print_result(int result)
{
    if (!is_invalid_input)
    {
        if (0 == result)
        {
            cout << NOT_FOUND << endl;
        }
        else
        {
            cout << result << endl;
        }
    }
    else
    {
        cout << NOT_FOUND << endl;
    }
}

int main(int argc, char const *argv[])
{
    freopen("more_than_half.in", "r", stdin);
    srand((unsigned int)time(NULL));
    
    int length = 0;
    while (cin >> length)
    {
        int *array = new int[length];
        for (int i = 0; i < length; ++i)
        {
            cin >> array[i];
        }

        int result = get_half_more(array, length);   
        print_result(result);
        delete[] array;
    }

    fclose(stdin);

    return 0;
}
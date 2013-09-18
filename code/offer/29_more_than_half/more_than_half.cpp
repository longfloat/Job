#include <iostream>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;

bool is_invalid_input = false;

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

void print_arr(int *a, int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

int median3(int *a, int start, int end)
{
    int center = (start + end) / 2;
    if (a[center] < a[start])
    {
        swap(a[start], a[center]);
    }

    if (a[end] < a[start])
    {
        swap(a[start], a[end]);
    }

    if (a[end] < a[center])
    {
        swap(a[center], a[end]);
    }

    swap(a[center], a[end - 1]);
    return a[end - 1];
}

int partition(int *a, int start, int end)
{
    if (start >= end)
    {
        return start;
    }
    int pivot = median3(a, start, end);
    int i = start, j = end - 1;
    for (; ;)
    {
        while (a[++i] < pivot) {}
        while (pivot < a[--j]) {}
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
        {
            break;
        }
    }

    swap(a[i], a[end - 1]);
    return i;
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

    // 循环退出时到数组中间位置的值
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
            cout << "no number is more than half!" << endl;
        }
        else
        {
            cout << "number for more than half is: " << result << endl;
        }
    }
    else
    {
        cout << "invlid input!" << endl;
    }
}

int main(int argc, char const *argv[])
{
    freopen("more_than_half.in", "r", stdin);
    freopen("more_than_half.out", "w", stdout);
    int length = 0;
    while (cin >> length)
    {
        cout << "------------------------" << endl;
        int *array = new int[length];
        for (int i = 0; i < length; ++i)
        {
            cin >> array[i];
        }

        cout << "the array: ";
        print_arr(array, length);
        int result = get_half_more(array, length);   
        print_result(result);
        delete[] array;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

/**
find times of a number occurred in a sorted array
returns: -1: invalid input (array is NULL or length is negative);
         0: number is not in the array;
         others(an positive int): times the number occurred in the array.
*/
int get_times_of_num_in_array(int *a, int length, int number)
{
    if (NULL==a || length<=0)
    {
        return -1;
    }

    int low = 0, high = length - 1;
    int middle;
    while (low < high)
    {
        middle = (low + high) >> 2;
        if (a[middle] < number)
        {
            low = middle + 1;
        }
        else if (number < a[middle])
        {
            high = middle - 1;
        }
        else
            break;
    }

    if (low < high)
    {
        // find the number
        int count = 1;
        low = high = middle;

        // search up to find numbers that equal to the found.
        while ((high<length) && (a[++high]==number))
        {
            ++count;
        }

        // search down to find numbers that equal to the found.
        while ((low>=0) && (a[--low]==number))
        {
            ++count;
        }

        return count;
    }
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    freopen("times_of_num_in_array.in", "r", stdin);
    int length, number;
    while (cin >> length)
    {
        cin >> number;
        int *a = new int[length];
        for (int i = 0; i < length; ++i)
        {
            cin >> a[i];
        }
        cout << get_times_of_num_in_array(a, length, number) << endl;
    }
    fclose(stdin);
    return 0;
}
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

long long count = 0;
int merge_combine(int *data, int *tmp, int start, int center, int end)
{
    int i = start;
    int j = center + 1;
    int index = start;
    while ((i <= center) && (j <= end))
    {
        if (data[i] > data[j])
        {
            // for (int k = i; k <= center; ++k)
            // {
            //     cout << "(" << data[k] << "," << data[j] << ")" << endl;
            // }
            count = count + center - i + 1;
            tmp[index++] = data[j++];
        }
        else
        {
            tmp[index++] = data[i++];
        }
    }

    while (i <= center)
        tmp[index++] = data[i++];

    while (j <= end)
        tmp[index++] = data[j++];

    for (index = start; index <= end; ++index)
    {
        data[index] = tmp[index];
    }

    return count;
}

void merge_sort(int *data, int *tmp, int start, int end)
{
    if (start < end)
    {
        int center = (start + end) / 2;
        merge_sort(data, tmp, start, center);
        merge_sort(data, tmp, center + 1, end);
        merge_combine(data, tmp, start, center, end);
    }
}

int main(int argc, char const *argv[])
{
    freopen("inverse_order.in", "r", stdin);

    int length;
    while (cin >> length)
    {
        count = 0;
        int *data = new int[length];
        int *tmp = new int[length];
        for (int i = 0; i < length; ++i)
        {
            cin >> data[i];
        }
        merge_sort(data, tmp, 0, length - 1);
        cout << count << endl;
        delete[] data;
        delete[] tmp;
    }
    fclose(stdin);
    return 0;
}
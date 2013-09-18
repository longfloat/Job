/**
* 打印螺旋队列
* 给定螺旋队列中某值的坐标, 返回该坐标对应的值
* 如以下的螺旋队列:
43  44  45  46  47  48  49
42  21  22  23  24  25  26
41  20  7   8   9   10  27
40  19  6   1   2   11  28
39  18  5   4   3   12  29
38  17  16  15  14  13  30
37  36  35  34  33  32  31
* 1为螺旋队列起点, 坐标为(0,0),x轴正向为水平向右, y轴正向为垂直向下
*/

#include <iostream>
#include <cstdlib> // abs
using std::cout;
using std::cin;
using std::endl;

int max(int a, int b)
{
    return (a>b) ? a : b;
}

int get_spiral_queue(int x, int y)
{
    int level = max(abs(x), abs(y));
    int max_round = (2*level-1) * (2*level-1);
    int value = 0;
    if (y == -level)
    {
        // 上边
        // 对于最右上角的元素, 它的下一个元素是处于本层的
        // 为了处理最右上角的元素, 右边的判断必须在上边之后
        value = max_round + 7*level + x;
    }
    else if (x == -level)
    {
        // 左边
        value = max_round + 5*level - y;
    }
    else if (y == level)
    {
        // 下边
        value = max_round + 3*level - x;
    }
    else if (x = level)
    {
        // 右边
        value = max_round + level + y;
    }

    return value;
}

int main()
{
    int dimension = 3;
    //cout << "input the dimension: ";
    //cin >> dimension;
    for (int y = -dimension; y <= dimension; ++y)
    {
        for (int x = -dimension; x <= dimension; ++x)
        {
            cout << get_spiral_queue(x, y);
            if (x != dimension)
            {
                cout << "\t";
            }
        }
        cout << endl;
    }
}
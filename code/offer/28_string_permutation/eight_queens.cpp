/**
* 八皇后问题
* 在8×8的国际象棋上摆放八个皇后, 使其不能相互攻击, 
* 即任意两个皇后不得处在同一行、同一列或者同一对角斜线上.
* 下图中的每个1表示一个皇后, 这就是一种符合条件的摆放方法.
*      0 0 1 0 0 0 0 0
*      0 0 0 0 0 1 0 0
*      0 1 0 0 0 0 0 0
*      0 0 0 0 0 0 1 0
*      1 0 0 0 0 0 0 0
*      0 0 0 1 0 0 0 0
*      0 0 0 0 0 0 0 1
*      0 0 0 0 1 0 0 0
* 请求出总共有多少种摆法.
*/
#include <iostream>
using std::cout;
using std::endl;

int solution = 1;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool is_suitable_queens(int col[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = i+1; j < length; ++j)
        {
            if ((col[i]-col[j]==i-j) || (col[i]-col[j]==j-i))
            {
                return false;
            }
        }
    }

    return true;
}

void print_queens(int col[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (col[i]==j)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void permutation(int col[], int length, int index)
{
    if (index == length)
    {
        if (is_suitable_queens(col, length))
        {
            cout << "solution " << solution << ": " << endl;
            print_queens(col, length);
            ++solution;
        }
    }
    else
    {
        for (int i = index; i < length; ++i)
        {
            swap(col[i], col[index]);
            permutation(col, length, index+1);
            swap(col[i], col[index]);
        }
    }
}

int main(int argc, char const *argv[])
{
    const int QUEEN_NUM = 8;
    int col[QUEEN_NUM];
    for (int i = 0; i < QUEEN_NUM; ++i)
    {
        col[i] = i;
    }
    permutation(col, QUEEN_NUM, 0);
    return 0;
}
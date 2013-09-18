/**
* 给出了一个n*n的矩形, 编程求从左上角到右下角的路径数(n > =2), 
* 限制只能向右或向下移动, 不能回退. 例如当n=2时, 有6条路径.
*/
#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

long long get_steps(int x, int y)
{
    long long steps[x+1][y+1];
    steps[0][0] = 0;

    for (int i = 1; i <= x; ++i)
        steps[i][0] = 1;

    for (int j = 1; j <= y; ++j)
        steps[0][j] = 1;

    for (int i = 1; i <= x; ++i)
        for (int j = 1; j <= y; ++j)
            steps[i][j] = steps[i-1][j] + steps[i][j-1];

    return steps[x][y];
}

int main(int argc, char const *argv[])
{
    freopen("08.in", "r", stdin);
    int x, y;
    while (cin >> x >> y)
    {
        cout << x << "x" << y << ":\t";
        cout << get_steps(x, y) << endl;
    }

    fclose(stdin);
    return 0;
}
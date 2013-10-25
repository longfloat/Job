/**
* 初级题：从考试成绩中划出及格线 
* 10个学生考完期末考试评卷完成后，A老师需要划出及格线，要求如下：
* (1) 及格线是10的倍数；
* (2) 保证至少有60%的学生及格；
* (3) 如果所有的学生都高于60分，则及格线为60分
* 
* 输入：输入10个整数，取值0~100
* 输出：输出及格线，10的倍数
 **/
#include <algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

const int SIXTY = 60;
int get_average(vector<int> &scores)
{
    if (scores.empty())
        return 0;

    sort(scores.begin(), scores.end());

    if (*(scores.begin()) >= SIXTY)
        return SIXTY;

    return (scores[4] / 10 * 10);
}

int main(int argc, char const *argv[])
{
    freopen("primary.in", "r", stdin);
    const int N = 10;
    vector<int> scores(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> scores[i];
        cout << get_average(scores) << endl;
    }

    fclose(stdin);
    return 0;
}
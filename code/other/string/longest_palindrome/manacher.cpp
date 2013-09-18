#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 300010;
int n, p[N];
char s[N], str[N];

#define _min(x, y) ((x)<(y)?(x):(y))

void kp()
{
    int i;
    int mx = 0;
    int id;
    for (i = n; str[i] != 0; i++)
        str[i] = 0; //没有这一句有问题。。就过不了ural1297，比如数据：ababa aba
    for (i = 1; i < n; i++)
    {
        if ( mx > i )
            p[i] = _min( p[2 * id - i], p[id] + id - i );
        else
            p[i] = 1;
        for (; str[i + p[i]] == str[i - p[i]]; p[i]++)
            ;
        if ( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

void init()
{
    int i, j, k;
    str[0] = '$';
    str[1] = '#';
    for (i = 0; i < n; i++)
    {
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }
    n = n * 2 + 2;
    s[n] = 0;
}

int main()
{
    freopen("longest_palindrome.in", "r", stdin);
    int i, ans, index=0;
    while (scanf("%s", s) != EOF)
    {
        n = strlen(s);
        init();
        kp();
        ans = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i] > ans)
            {
                ans = p[i];
                index = i;
            }
        }
        // index = index >> 2;
        // ans = ans >> 2;

        for (int j = index-ans-1; j < index+ans; ++j)
        {
            if (str[j] != '#' && str[j]!='$')
            {
                printf("%c", str[j]);
            }   
        }
        //printf("%d\n", ans-1);
        printf("\n");
    }
    fclose(stdin);
    return 0;
}
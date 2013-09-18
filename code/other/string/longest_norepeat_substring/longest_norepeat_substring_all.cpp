#include <iostream>
using namespace std;

/* 最长不重复子串 设串不超过30
 * 我们记为 LNRS
 */
int maxlen;
int maxindex;
void output(char *arr);

/* LNRS 基本算法 hash */
char visit[256];

void LNRS_hash(char *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        memset(visit, 0, sizeof visit);
        visit[arr[i]] = 1;
        for (int j = i + 1; j < size; ++j)
        {
            if (visit[arr[j]] == 0)
            {
                visit[arr[j]] = 1;
            }
            else
            {
                if (j - i > maxlen)
                {
                    maxlen = j - i;
                    maxindex = i;
                }
                break;
            }
        }
    }
    output(arr);
}

/* LNRS dp */
int dp[30];

void LNRS_dp(char *arr, int size)
{
    int i, j;
    maxlen = maxindex = 0;

    dp[0] = 1;
    for (i = 1; i < size; ++i)
    {
        for (j = i - 1; j >= 0; --j)
        {
            if (arr[j] == arr[i])
            {
                dp[i] = i - j;
                break;
            }
        }
        if (j == -1)
        {
            dp[i] = dp[i - 1] + 1;
        }
        if (dp[i] > maxlen)
        {
            maxlen = dp[i];
            maxindex = i + 1 - maxlen;
        }
    }
    output(arr);
}

/* LNRS dp + hash 记录下标 */
void LNRS_dp_hash(char *arr, int size)
{
    memset(visit, -1, sizeof visit);
    memset(dp, 0, sizeof dp);
    maxlen = maxindex = 0;
    dp[0] = 1;
    visit[arr[0]] = 0;

    for (int i = 1; i < size; ++i)
    {
        if (visit[arr[i]] == -1)
        {
            dp[i] = dp[i - 1] + 1;
            visit[arr[i]] = i; /* 记录字符下标 */
        }
        else
        {
            dp[i] = i - visit[arr[i]];
        }
        if (dp[i] > maxlen)
        {
            maxlen = dp[i];
            maxindex = i + 1 - maxlen;
        }
    }
    output(arr);
}

/* LNRS dp + hash 优化 */
void LNRS_dp_hash_impro(char *arr, int size)
{
    memset(visit, -1, sizeof visit);
    maxlen = maxindex = 0;
    visit[arr[0]] = 0;
    int curlen = 1;

    for (int i = 1; i < size; ++i)
    {
        if (visit[arr[i]] == -1)
        {
            ++curlen;
            visit[arr[i]] = i; /* 记录字符下标 */
        }
        else
        {
            curlen = i - visit[arr[i]];
        }
        if (curlen > maxlen)
        {
            maxlen = curlen;
            maxindex = i + 1 - maxlen;
        }
    }
    output(arr);
}

/* 输出LNRS */
void output(char *arr)
{
    if (maxlen == 0)
    {
        printf("NO LNRS\n");
    }
    printf("The len of LNRS is %d\n", maxlen);

    int i = maxindex;
    while (maxlen--)
    {
        printf("%c", arr[i++]);
    }
    printf("\n");
}

void main()
{
    char arr[] = "abcdeab";

    /* LNRS 基本算法 */
    LNRS_hash(arr, strlen(arr));

    /* LNRS dp */
    LNRS_dp(arr, strlen(arr));

    /* LNRS dp + hash记录下标 */
    LNRS_dp_hash(arr, strlen(arr));

    /* LNRS dp + hash improved */
    LNRS_dp_hash_impro(arr, strlen(arr));
}
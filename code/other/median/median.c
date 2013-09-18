
#include <stdio.h>
#include <stdlib.h>


/* 从数组A和B中找下中位数 */
int find_median(int *A, int *B, int m, int n, int s, int t)
{
    int  p, c;

    c = (m+n-1)/2;  /* 有多少个数小于下中位数 */
    p = (s+t)/2;

    /* 如果下中位数不在A中，就从数组B找 */
    if (s > t) {
        return find_median(B, A, n, m, 0, n-1);
    }

    /* 数组A中有p个数小于A[p], 当且进当数组B中有c-p个数小于A[p], A[p]才是中位数 */
    if (A[p] >= B[c-p-1] && A[p] <= B[c-p]) {
        return A[p];
    }

    /* A[p]太小了，从数组A中找一个更大的数尝试 */
    if (A[p] < B[c-p-1]) {
        return find_median(A, B, m, n, p+1, t);
    }

    /* A[p]太大了，从数组A中找一个更小的数尝试 */
    return find_median(A, B, m, n, s, p-1);
}

int main()
{
    int m, n;
    // int A[]={1,3,5,7,8,9,10,12,24,45,65};
    // int B[]={2,4,6,10,11,12,13,14,17,19,20,34,44,45,66,99};
    int A[]={0, 1, 2, 3};
    int B[] = {10, 11, 12, 14, 15};

    m = sizeof(A)/sizeof(int);
    n = sizeof(B)/sizeof(int);

    printf("%d\n", find_median(A, B, m, n, 0, m-1));

    return 0;
}
#include <cstdio>

void swap_1(int a , int b)
{
    int c;
    c = a;
    a = b;
    b = c;
    return ;
}
void swap_2(int &a , int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
    return ;
}
void swap_3(int *a , int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
    return ;
}

void swap_4(int *a, int *b)
{
    int *tmp;
    tmp = a;
    a = b;
    b = tmp;
    return ;
}

int main(void)
{
    int a = 100;
    int b = 200;
    swap_1(a , b);
    printf("a = %d , b = %d\n",a , b);
    swap_2(a , b);
    printf("a = %d , b = %d\n",a , b);
    // swap_3(&a , &b);
    // printf("a = %d , b = %d\n",a , b);
    swap_4(&a , &b);
    printf("a = %d , b = %d\n",a , b);
    return 0;
}
#include <stdio.h>
#include <string.h>

typedef unsigned char u_int8_t;
void test(u_int8_t len, char *s)
{
    char a[20];//6+14,ftp://
    u_int8_t len2;
    len2 = len + 6;
    if (len2 > 20)
    {
        printf("the host is so long\n");
    }
    else
    {
        strncpy(a, "ftp://", 6);
        strncpy(a + 6, s, len);
        a[len + 6] = '\0';
        printf("host:%s\n", a);
    }
}


int main(int argc, char **argv)
{
    if (argc > 2)
    {
        printf("please input the host\n");
        return 1;
    }
    u_int8_t len;
    len = strlen(argv[1]);
    printf("len:%d\n", len);
    test(len, argv[1]);
    return 1;
}
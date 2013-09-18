#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using std::cout;
using std::endl;

void get_memory1(char *p)
{
    p = (char *)malloc(100);
}

void test1(void)
{
    char *str = NULL;
    get_memory1(str);

    if (NULL == str)
    {
        cout << "NULL" << endl;
        return;
    }
    strcpy(str, "hello world 1");

    printf(str);
}

// char* get_memory2(void)
// {
//     char p[] = "hello world 2";
//     return p;
// }

// void test2(void)
// {
//     char *str = NULL;
//     str = get_memory2();

//     // if (NULL == str)
//     // {
//     //     cout << "NULL" << endl;
//     //     return;
//     // }

//     printf(str);
// }

char* get_memory4(void)
{
    char *p = "hello";
    return p;
}

void test4(void)
{
    char *str = NULL;
    str = get_memory4();
    strcpy(str, "abc");
    printf(str);
}

int main(int argc, char const *argv[])
{
    //test1();
    //test2();
    test4();
    return 0;
}
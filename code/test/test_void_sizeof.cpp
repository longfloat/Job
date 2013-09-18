#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using std::cout;
using std::endl;

void get_memory(char *p)
{
    p = (char *)malloc(100);
}

void test(void)
{
    char *str = NULL;
    get_memory(str);

    if (NULL == str)
    {
        cout << "NULL" << endl;
        return;
    }
    strcpy(str, "hello world");

    printf(str);
}

int main(int argc, char const *argv[])
{
    // void *ptr = malloc(100);
    // void *ptr2;
    // cout << "sizeof(ptr)=" << sizeof(ptr) << endl;
    // cout << "sizeof(ptr2)=" << sizeof(ptr2) << endl;
    test();
    return 0;
}
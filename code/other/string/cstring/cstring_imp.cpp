#include <iostream>
using std::cout;
using std::endl;

char* strcpy(char *dest, const char *src)
{
    if (NULL==dest || NULL==src)
    {
        return NULL;
    }

    char *tmp = dest;
    while ((*dest++ = *src++) != '\0')
    {}
    
    return tmp;
}

char* strcat(char *dest, const char *src)
{
    if (NULL==dest || NULL==src)
    {
        return NULL;
    }

    char *tmp = dest;
    while (*dest != '\0')
    {
        ++dest;
    }

    while ((*dest++ = *src++) != '\0')
    {}

    return tmp;
}

int main(int argc, char const *argv[])
{
    char str1[50] = "hello";
    char str2[50];

    strcpy(str2, str1);
    cout << str2 << endl;
    strcat(str2, " world!");
    cout << str2 << endl;

    return 0;
}
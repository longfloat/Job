#include "String.h"
#include <cstring>

String(const char *str)
{
    if (NULL == str)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length + 1];

        // 将str中的所有字符赋值到为m_data新分配的内存中
        // 这可以保证根据一个字符串常量创建一个String对象
        // e.g. String str("hello");
        strcpy(m_data, str);
    }
}

String::String(const String &orig)
{
    int length = strlen(orig.m_data);
    m_data = new char[length];
    strcpy(m_data, orig.m_data);
}

/**
* 此处的const是必须的:
* 如果不加const, 当使用一个const String对象进行构造时,
* 由于参数是non-const的, 
* 而一个const变量是不能随便转换成non-const的.
* 
*/
String& operator=(const String &rhs)
{
    if (&rhs != this)
    {
        // 释放原有的内存资源
        delete[] m_data;

        // 分配新的内存资源, 并复制内容
        int length = strlen(rhs.m_data);
        m_data = new char[length];
        strcpy(m_data, rhs.m_data);
    }

    return *this;
}

String::~String()
{
    delete[] m_data;
}
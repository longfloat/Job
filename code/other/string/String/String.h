#ifndef STRING_H
#define STRING_H

class String
{
public:
    String(const char *str = NULL);
    String(const String &orig);
    String& operator=(const String &rhs);
    ~String();

private:
    char *m_data;
};

#endif // STRING_H
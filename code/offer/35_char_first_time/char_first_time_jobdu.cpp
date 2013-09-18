#include <iostream>
#include <string>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int get_char_of_first_time(string &str)
{
    if (0 == str.size())
    {
        return -1;
    }

    const int ASCII_COUNT = 256;
    size_t hash_table[ASCII_COUNT] = {0};

    // build the hash table.
    for (string::iterator iter=str.begin(); iter!=str.end(); ++iter)
    {
        ++hash_table[*iter];
    }

    int index = -1;
    for (string::iterator iter=str.begin(); iter!=str.end(); ++iter)
    {
        ++index;
        if (1 == hash_table[*iter])
        {
            return index;
        }
    }

    // return -1 if there is no char that occur once first time.
    return -1;
}

int main(int argc, char const *argv[])
{
    freopen("char_first_time.in", "r", stdin);
    string str;
    while (cin >> str)
    {
        cout << get_char_of_first_time(str) << endl;
    }

    fclose(stdin);
    return 0;
}
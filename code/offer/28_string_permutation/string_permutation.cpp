#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

string s("");
void permutation(char *str, char *begin)
{   
    if (*begin == '\0')
    {
        //cout << "----------------------------------------" << endl;
        cout << s << str << endl;
        //cout << str << endl;
        //cout << "----------------------------------------" << endl;
    }
    else
    {
        for (char *p=begin; *p!='\0'; ++p)
        {
            s.push_back('|');
            s.push_back('_');
            s.push_back('_');
            s.push_back('_');
            s.push_back('_');
            s.push_back('_');
            s.push_back('_');

            //cout << ">>" ;
            cout << s << str << endl;
            //cout << str << endl;
            //cout << "*p=" << *p << " ";
            //cout << "*begin=" << *begin << endl;
            char temp = *p;
            *p = *begin;
            *begin = temp;
            permutation(str, begin + 1);
            s.erase(s.size()-1, 1);
            s.erase(s.size()-1, 1);
            s.erase(s.size()-1, 1);
            s.erase(s.size()-1, 1);
            s.erase(s.size()-1, 1);
            s.erase(s.size()-1, 1);
            s.erase(s.size()-1, 1);
            temp = *p;
            *p = *begin;
            *begin = temp;
        }
    }
}

void permutation(char *str)
{
    if (NULL == str)
    {
        return;
    }
    permutation(str, str);
}

int main(int argc, char const *argv[])
{
    char s[] = "abc";
    permutation(s);
    return 0;
}
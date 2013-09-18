#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    const string s("hello");
    for (string::const_reverse_iterator riter=s.rbegin(); riter != s.rend(); ++riter)
    {
        cout << *riter << endl;
    }
    return 0;
}
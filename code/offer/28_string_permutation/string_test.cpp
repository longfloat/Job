#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    string s("hello world");
    s[s.size() - 1] = 'h';
    cout << s << endl;
    return 0;
}
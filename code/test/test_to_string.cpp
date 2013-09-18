#include <string>
#include <iostream>
#include <sstream> // ostringstream
using std::string;
using std::cout;
using std::endl;
using std::ostringstream;


template <typename T>
string number_to_string (T number)
{
    ostringstream ss;
    ss << number;
    return ss.str();
}
int main(int argc, char const *argv[])
{
    string s1("abc");
    string s2("abc");
    int a = 12345;
    string s3("0");
    string s4(a + s3);
    cout << s4 << endl;
    cout << std::boolalpha << (s1 >= s2) << endl;
    return 0;
}
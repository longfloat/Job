#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

void get_subsequence_recursive(const string &str, const string &prefix)
{
    if (str.empty())
    {
        return;
    }
    for (size_t index=0; index<str.size(); ++index)
    {
        const char ch = str.at(index);
        string s(str);
        //for (size_t j=0, j<index; ++j)
        //{
        	s.erase(0, index-1);
        //}
        cout << prefix + ch << endl;
        get_subsequence_recursive(s, prefix+ch);
    }
}

int main(int argc, char const *argv[])
{
    string str;
    cout << "input a string: ";
    cin >> str;
    cout << "---------------" << endl;
    get_subsequence_recursive(str, "");
    return 0;
}
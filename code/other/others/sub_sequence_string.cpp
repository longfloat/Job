#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;


void get_subsequence_core(const char ch, vector<string> &sv)
{
    vector<string> tmp(sv);

    for (std::vector<string>::iterator iter = tmp.begin(); iter != tmp.end(); ++iter)
    {
        string s(*iter);
        s = ch + s;
        //cout << s << endl;
        sv.push_back(s);
    }
}

void get_subsequence(const string &str, vector<string> &sv)
{
    //cout << "str.length()==" << str.length() << endl;

    for (string::const_reverse_iterator riter=str.rbegin(); riter != str.rend(); ++riter)
    {
        string s(1, *riter);
        
        get_subsequence_core(*riter, sv);
        sv.push_back(s);
    }
}

void print_vector(vector<string> &sv)
{
    for (std::vector<string>::iterator iter = sv.begin(); iter != sv.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
    cout << "total = " << sv.size() << endl;
}

int main(int argc, char const *argv[])
{
    string str;
    cout << "input a string: ";
    cin >> str;
    vector<string> seqs;
    get_subsequence(str, seqs);
    cout << "---------------" << endl;
    print_vector(seqs);
    return 0;
}
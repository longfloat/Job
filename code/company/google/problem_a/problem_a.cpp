#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstddef>  // std::size_t
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const string MULTI_TWO("double");
const string MULTI_THREE("triple");
const string MULTI_FOUR("quadruple");
const string MULTI_FIVE("quintuple");
const string MULTI_SIX("sextuple");
const string MULTI_SEVEN("septuple");
const string MULTI_EIGHT("octuple");
const string MULTI_NINE("nonuple");
const string MULTI_TEN("decuple");
const string MULTI_DEFAULT("");

const string NUM_ZERO("zero");
const string NUM_ONE("one");
const string NUM_TWO("two");
const string NUM_THREE("three");
const string NUM_FOUR("four");
const string NUM_FIVE("five");
const string NUM_SIX("six");
const string NUM_SEVEN("seven");
const string NUM_EIGHT("eight");
const string NUM_NINE("nine");
const string NUM_DEFAULT("");

const char DASH = '-';

string get_multi(int number)
{
    switch(number)
    {
        case 2:
            return MULTI_TWO;

        case 3:
            return MULTI_THREE;

        case 4:
            return MULTI_FOUR;

        case 5:
            return MULTI_FIVE;

        case 6:
            return MULTI_SIX;

        case 7:
            return MULTI_SEVEN;

        case 8:
            return MULTI_EIGHT;

        case 9:
            return MULTI_NINE;

        case 10:
            return MULTI_TEN;

        default:
            return MULTI_DEFAULT;
    }
}

string get_num(int num)
{
    switch(num)
    {
        case '0':
            return NUM_ZERO;

        case '1':
            return NUM_ONE;

        case '2':
            return NUM_TWO;

        case '3':
            return NUM_THREE;

        case '4':
            return NUM_FOUR;

        case '5':
            return NUM_FIVE;

        case '6':
            return NUM_SIX;

        case '7':
            return NUM_SEVEN;

        case '8':
            return NUM_EIGHT;

        case '9':
            return NUM_NINE;

        default:
            return NUM_DEFAULT;
    }
}

vector<int> get_format(const string &format)
{
    vector<string> sv;

    size_t start = 0;
    size_t found = format.find_first_of(DASH);
    while (found != string::npos)
    {
        sv.push_back(format.substr(start, found - start));
        start = found + 1;
        found = format.find_first_of(DASH, start);
    }

    sv.push_back(format.substr(start));

    vector<int> iv(sv.size());
    for (vector<string>::iterator iter = sv.begin(); iter != sv.end(); ++iter)
    {
        char *buffer = new char[(*iter).length() + 1];
        int num;
        strcpy(buffer, iter->c_str());
        sscanf(buffer, "%d", &num);
        iv.push_back(num);
        delete[] buffer;
    }

    return iv;
}

string get_read(const string &phone, const string &format)
{
    vector<int> iv = get_format(format);
    string read;
    size_t start = 0;
    for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); ++iter)
    {
        string str = phone.substr(start, *iter);
        size_t s1 = 0;
        size_t s2 = s1;
        int count = 0;
        while (s1 != str.length() && s2 != str.length() && s1 <= s2)
        {
            while (s2 != str.length() && str[s2] == str[s1])
            {
                ++count;
                ++s2;
            }
            string multi = get_multi(count);
            read.append(multi);
            if (multi != MULTI_DEFAULT)
                read.append(" ");
            read.append(get_num(str[s1]));
            read.append(" ");

            s1 = s2;
            s2 = s1;
            count = 0;
        }

        start = start + *iter;
    }

    return read;
}

int main(int argc, char const *argv[])
{
    cout << "small(0) or large(1): ";
    int type;
    cin >> type;
    if (0 == type)
    {
        freopen("A-small-practice.in", "r", stdin);
        freopen("A-small-practice.out", "w", stdout);
    }
    else if (1 == type)
    {
        freopen("A-large-practice.in", "r", stdin);
        freopen("A-large-practice.out", "w", stdout);
    }
    else
    {
        cout << "invalid input!!!" << endl;
        return 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t;  ++i)
    {
        string phone, format;
        vector<size_t> svec;
        cin >> phone >> format;
        cout << "Case #" << i+1 << ": " << get_read(phone, format) << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class test_static
{
public:
    static int value;
    test_static()
    {
        cout << "construct!" << endl;
    }
};
template <typename T> int test_static<T>::value = 0;

int main(int argc, const char *argv[])
{
    test_static<int> t_int;
    test_static<float> t_float;
    test_static<char> t_char;
    cout << test_static<double>::value << endl;
    return 0;
}
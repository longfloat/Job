#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main(int argc, char const *argv[])
{
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    for (unsigned int i=array.size()-1; i>=0; --i)
    {
        cout << array[i];
    }
    return 0;
}
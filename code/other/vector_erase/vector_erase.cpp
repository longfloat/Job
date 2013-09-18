#include <iostream>
#include <vector>
#include <cstdio>
using std::cout;
using std::endl;
using std::cin;
using std::vector;

void print(vector<int> &v)
{
    if (v.empty())
    {
        cout << "empty!" << endl;
        return ;
    }

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

/**
* 删除vector<int>中所有值为value的元素
*/
void remove_same(vector<int> &v, const int &value)
{
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        if (value == *iter)
        {
            v.erase(iter);
            --iter;
        }
    }
}

void remove_same2(vector<int> &v, const int &value)
{
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
    {
        while ((*iter) == value)
        {
            v.erase(iter);
            if (iter == v.end())
            {
                break;
            }
        }

        if (iter == v.end())
        {
            break;
        }
    }
}


int main(int argc, char const *argv[])
{
    freopen("vector_erase.in", "r", stdin);
    freopen("vector_erase.out", "w", stdout);

    // int a[] = {0, 1, 3, 2, 5, 1, 8, 1, 9, 20};
    // // sizeof(a)/sizeof(int)计算整型数组元素的个数
    // vector<int> iv(a, a + sizeof(a)/sizeof(int));
    
    int length = 0;
    while (cin >> length)
    {
        vector<int> iv;
        int value = 0;
        cin >> value;
        int data = 0;
        for (int i = 0; i < length; ++i)
        {
            cin >> data;
            iv.push_back(data);
        }

        cout << "--------------------" << endl;
        cout << "befor remove " << value << ": ";
        print(iv);
        remove_same(iv, value);
        cout << "after remove " << value << ": ";
        print(iv);
    }
  
    fclose(stdin);
    fclose(stdout);
    return 0;
}
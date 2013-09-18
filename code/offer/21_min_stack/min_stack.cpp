#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

template <typename T>
class min_stack
{
public:
    min_stack() {}
    ~min_stack() {}
    void push(const T&);
    T pop();
    T min() const;
    bool empty() const;
private:
    stack<T> m_data;
    stack<T> m_min;
};

template <typename T> void min_stack<T>::push(const T &data)
{
    cout << "&data=" << &data <<endl;
    m_data.push(data);
    if (m_min.empty())
    {
        m_min.push(data);
    }
    else
    {
        data<m_min.top() ? m_min.push(data) : m_min.push(m_min.top());
    }
}

template <typename T> T min_stack<T>::pop()
{
    T value = m_data.top();
    m_min.pop();
    m_data.pop();
    return value;
}

template <typename T> T min_stack<T>::min() const
{
    return m_min.top();
}

template <typename T> bool min_stack<T>::empty() const
{
    return m_data.empty();
}

template<typename T>
void print_stack(min_stack<T> s)
{
    min_stack<T> tmp(s);
    cout << "the stack(the first is the top): ";
    while (!s.empty())
    {
        cout << s.pop() << " ";
    }
    cout << endl;
}

int main()
{
    const int COUNT = 5;
    min_stack<int> mystack;
    for (int i = 0; i < COUNT; ++i)
    {
        cout << "&i=" << &i <<endl;
        mystack.push(i);
        mystack.push(COUNT - i);
    }

    print_stack(mystack);
    cout << "the min value: " << mystack.min() << endl;

    cout << "insert value: " << 21 << endl;
    mystack.push(21);
    print_stack(mystack);

    while (!mystack.empty())
    {
        cout << "-------------------" << endl;
        cout << "pop: " << mystack.pop() << endl;
        print_stack(mystack);
        cout << "min value:" << mystack.min() << endl;
    }
    
    return 0;
}
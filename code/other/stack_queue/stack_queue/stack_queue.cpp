#include <iostream>
#include <stack>
using std::stack;
using std::cout;
using std::endl;

/**
* 使用两个栈实现队列
* 栈使用STL的stack
*/
template <typename T> class StackQueue
{
public:
    StackQueue() {};
    ~StackQueue() {};
    // 向队列中添加一个元素
    void push(const T &data);
    // 删除队头元素
    T pop();
    void print() const;

private:
    stack<T> stack1;    // 进队时使用
    stack<T> stack2;    // 出队时使用
};

template <typename T>
void StackQueue<T>::push(const T &data)
{
    stack1.push(data);
}

template <typename T>
T StackQueue<T>::pop()
{
    T head;
    if (stack2.empty())
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    if (stack2.empty())
    {
        cout << "empty queue! no head!" << endl;
    }
    else
    {
        head = stack2.top();
        stack2.pop();
    }
    
    return head;
}

template <typename T>
void StackQueue<T>::print() const
{
    if (stack1.empty() && stack2.empty())
    {
        cout << "empty queue!" << endl;
    }
    else
    {
        stack<T> tmp1(stack1);
        stack<T> tmp2(stack2);

        while (!tmp1.empty() || !tmp2.empty())
        {
            while (!tmp2.empty())
            {
                cout << tmp2.top() << " ";
                tmp2.pop();
            }

            while (!tmp1.empty())
            {
                tmp2.push(tmp1.top());
                tmp1.pop();
            }
        }
        cout << endl;        
    }
}

int main()
{
    StackQueue<int> squeue;
    squeue.print();
    squeue.pop();
    for (int i = 0; i < 10; ++i)
    {
        squeue.push(i);
    }
    cout << "the queue: ";
    squeue.print();

    squeue.push(13);
    cout << "the queue after add 13: ";
    squeue.print();

    cout << "the queue after delete the head " << squeue.pop() << ": ";
    squeue.print();
}
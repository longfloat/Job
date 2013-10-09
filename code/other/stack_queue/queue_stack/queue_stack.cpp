template <typename T> class QueueStack
{
public:
    QueueStack() : q1_used(true), q2_used(false) {};
    ~QueueStack() {};
    // 向栈中添加一个元素
    void push(const T &data);
    // 删除栈顶元素
    T pop();
    void print() const;

private:
    queue<T> queue1;
    queue<T> queue2;
    bool q1_used;
    bool q2_used;
};

template <typename T>
void QueueStack<T>::push(const T &data)
{
    if (q1_used)
    {
        queue1.push(data);
    }
    else if (q2_used)
    {
        queue2.push(data);
    }
}

template <typename T>
T QueueStack<T>::pop()
{
    T head;
    if (q1_used)
    {
        if
        head = queue1.back();
        while (!queue1.empty())
        {
            queue2.push(queue1.front());
            queue1.pop();
        }

        q1_used = false;
        q2_used = true;
    }
    else if (q2_used)
    {
        head = queue2.back();
        while (!queue2.empty())
        {
            queue1.push(queue2.front());
            queue2.pop();
        }

        q1_used = true;
        q2_used = false;
    }

    return head;
}

template <typename T>
void QueueStack<T>::print() const
{
    if (q1_used)
    {
        for (int i = queue1.size(); i>=0; --i)
            cout << queue1[i] << " " << endl;
    }
}

int main(int argc, char const *argv[])
{
    if (queue1.empty() && queue2.empty())
    {
        cout << "empty stack()!" << endl;
    }
    else 
    return 0;
}
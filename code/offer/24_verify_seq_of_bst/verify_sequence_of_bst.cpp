#include <iostream>
using std::cout;
using std::endl;

bool verify_sequence_of_bst(int sequence[], int length)
{
    if (NULL==sequence || length<=0)
    {
        return false;
    }
    int root = sequence[length - 1];
    int i = 0;

    // 在序列中找到第一个大于根节点的值
    // 此点到根节点之间的序列即为右子树节点
    for (; i<length-1; ++i)
    {
        if (sequence[i] > root)
        {
            break;
        }
    }

    int j = i;
    // 在右子树序列中查找是否存在比根节点小的值
    // 如果存在, 说明这不是一棵二叉查找树.
    for (; j<length-1; ++j)
    {
        if (sequence[j] < root)
        {
            return false;
        }
    }

    // 递归检查左子树和右子树是否是二叉查找树的序列
    bool left = true;
    if (i > 0)
    {
        left = verify_sequence_of_bst(sequence, i);
    }

    bool right = true;
    if (i < length-1)
    {
        right = verify_sequence_of_bst(sequence+i, length-i-1);
    }

    return (left && right);
}

int main()
{
    int a[] = {2,7,4,9,8,11,12,13,20,16,15,10};
    cout << "a: " << verify_sequence_of_bst(a, 12) << endl;

    int b[] = {2};
    cout << "b: " << verify_sequence_of_bst(b, 1) << endl;

    int c[] = {7,4,6,5};
    cout << "c: " << verify_sequence_of_bst(c, 4) << endl;

    int *d = NULL;
    cout << "d: " << verify_sequence_of_bst(d, 0) << endl;

    int e[] = {5,7,6,9,11,10,8};
    cout << "e: " << verify_sequence_of_bst(e, 7) << endl;
}
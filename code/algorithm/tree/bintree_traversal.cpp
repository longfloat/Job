#include <iostream>
#include "bintree.h"
#include <stack>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

/**
* 根据树的前序遍历结果(包含了NULL指针, 用0表示)生成一棵二叉树
* 输入0表示NULL
* 对于叶子节点, 其左右子树均为NULL
*/
template <typename T>
void build_tree(bin_tree_node<T>* &root)
{
    root = new bin_tree_node<T>();
    //cout << "input data(0 if no data): ";
    cin >> root->data;
    if (0 == root->data)
    {
        delete root;
        root = NULL;
    }

    if (root != NULL)
    {
        build_tree(root->left);
        build_tree(root->right);
    }
}

/**
* 非递归前序遍历
*/
template <typename T>
void pre_order1(bin_tree_node<T>* root)
{
    stack<bin_tree_node<T>*> s;
    bin_tree_node<T> *p = root;
    while (p != NULL || !s.empty())
    {
        while (p != NULL)
        {
            cout << p->data << " ";
            s.push(p);
            p = p->left;
        }

        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    cout << endl;
}

template <typename T>
void pre_order2(bin_tree_node<T> *root)
{
    if (root != NULL)
    {
        stack<bin_tree_node<T>*> s;
        s.push(root);
        while (!s.empty())
        {
            bin_tree_node<T> *p = s.top();
            if (p != NULL)
                cout << p->data << " ";
            
            s.pop();

            if (p->right != NULL)
                s.push(p->right);

            if (p->left != NULL)
                s.push(p->left);
        }
        cout << endl;
    }
}

/**
* 递归前序遍历
*/
template <typename T>
void pre_order_r(bin_tree_node<T>* root)
{
    if (NULL == root)
        return;

    cout << root->data << " ";

    if (root->left !=  NULL)
        pre_order_r(root->left);

    if (root->right != NULL)
        pre_order_r(root->right);
}

/**
* 非递归中序遍历
*/
template <typename T>
void mid_order(bin_tree_node<T>* root)
{
    stack<bin_tree_node<T>*> s;
    bin_tree_node<T> *p = root;
    while (p != NULL || !s.empty())
    {
        // 一直向左到最左
        while (p != NULL)
        {
            s.push(p);
            p = p->left;
        }

        if (!s.empty())
        {
            p = s.top();
            s.pop();

            cout << p->data << " "; // 访问根节点
            p = p->right;   // 访问右子树
        }
    }
    cout << endl;
}

/**
* 递归中序遍历
*/
template <typename T>
void mid_order_r(bin_tree_node<T>* root)
{
    if (NULL == root)
        return;

    if (root->left != NULL)
        mid_order_r(root->left);

    cout << root->data << " ";

    if (root->right != NULL)
        mid_order_r(root->right);
}

/**
* 非递归后序遍历
* 
* 要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
* 如果P不存在左孩子和右孩子，则可以直接访问它；
* 或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
* 若非上述两种情况，则将P的右孩子和左孩子依次入栈，
* 这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。
*/
template <typename T>
void post_order(bin_tree_node<T>* root)
{
    stack<bin_tree_node<T>*> s;
    bin_tree_node<T> *cur = root;
    bin_tree_node<T> *pre = NULL;
    s.push(cur);
    while (!s.empty())
    {
        cur = s.top();
        if ((NULL==cur->left && NULL==cur->right) || 
            (pre!=NULL && (pre==cur->left || pre==cur->right)))
        {
            cout << cur->data << " ";
            s.pop();
            pre = cur;
        }
        else
        {
            if (cur->right != NULL)
                s.push(cur->right);

            if (cur->left != NULL)
                s.push(cur->left);
        }
    }
    cout << endl;
}

/**
* 递归后序遍历
*/
template <typename T>
void post_order_r(bin_tree_node<T>* root)
{
    if (NULL == root)
        return;

    if (root->left != NULL)
        post_order_r(root->left);

    if (root->right != NULL)
        post_order_r(root->right);

    cout << root->data << " ";
}

int main(int argc, char const *argv[])
{
    freopen("bintree_traversal.in", "r", stdin);
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "------------------------------" << endl;
        bin_tree_node<int> *root = NULL;
        build_tree(root);

        cout << "pre_order1:\t";
        pre_order1(root);
        cout << "pre_order2:\t";
        pre_order2(root);
        cout << "pre_order_r:\t";
        pre_order_r(root);
        cout << endl << endl;

        cout << "mid_order:\t";
        mid_order(root);
        cout << "mid_order_r:\t";
        mid_order_r(root);
        cout << endl << endl;

        cout << "post_order:\t";
        post_order(root);
        cout << "pst_order_r:\t";
        post_order_r(root);
        cout << endl;
    }
    fclose(stdin);
    return 0;
}
/**********************************************************
* 剑指offer 面试题27 二叉搜索树与双向链表
* 输入一棵二叉排序树, 将该二叉排序树转成一个排序的双向链表.
* 要求不能创建任何新节点, 只能调整树中节点指针的指向.
* 如输入以下二叉排序树:
*       10
*    /      \
*   6        14
*  /\        /\
* 4  8     12  16
* 输出双向链表:
* 4->6->8->10->12->14->16
* 4<-6<-8<-10<-12<-14<-16
**********************************************************/

#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

struct binary_tree_node
{
    int data;
    binary_tree_node *left;
    binary_tree_node *right;
};

/**
* 根据树的前序遍历结果(包含了NULL指针, 用0表示)生成一棵二叉树
* 输入0表示NULL
* 对于叶子节点, 其左右子树均为NULL
*/
void build_tree(binary_tree_node* &root)
{
    root = new binary_tree_node();
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

void pre_order(binary_tree_node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void convert_node(binary_tree_node *node, binary_tree_node* &last_node)
{
    if (NULL == node)
    {
        return;
    }

    binary_tree_node *current_node = node;
    if (current_node->left != NULL)
    {
        convert_node(current_node->left, last_node);
    }
    current_node->left = last_node;
    if (last_node != NULL)
    {
        last_node->right = current_node;
    }

    last_node = current_node;
    if (current_node->right != NULL)
    {
        convert_node(current_node->right, last_node);
    }

}

binary_tree_node* get_dlist_from_bst(binary_tree_node *root)
{
    binary_tree_node *last_node = NULL;
    convert_node(root, last_node);

    binary_tree_node *dlist_head = last_node;

    // dlist_head != NULL检测链表是否为空链表
    while (dlist_head != NULL && dlist_head->left != NULL)
    {
        dlist_head = dlist_head->left;
    }
    return dlist_head;
}

void print_dlist(binary_tree_node *head)
{
    binary_tree_node *node = head;
    if (NULL == node)
    {
        cout << "empty list!" << endl;
        return;
    }

    cout << "from left to right: ";
    while(node != NULL)
    {
        cout << node->data << " ";
        if (NULL == node->right)
        {
            break;
        }
        node = node->right;
    }
    cout << endl;

    cout << "from right to left: ";
    while(node != NULL)
    {
        cout << node->data << " ";
        if (NULL == node->left)
        {
            break;
        }
        node = node->left;
    }
    cout << endl;
}

void test(const char* in, const char *out)
{
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    binary_tree_node *root = NULL;
    build_tree(root);
    // cout << "pre_order: ";
    // pre_order(root);
    // cout << endl;
    binary_tree_node *head = get_dlist_from_bst(root);
    print_dlist(head);
    fclose(stdin);
    fclose(stdout);
}

int main(int argc, char const *argv[])
{
    test("bst_dlist.in", "bst_dlist.out");
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

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

int get_bintree_depth(binary_tree_node *root, vector<binary_tree_node*> &binv)
{
    if (NULL == root)
    {
        return 0;
    }

    binv.push_back(root);
    if (NULL==root->left && NULL==root->right)
    {
        return 0;
    }

    vector<binary_tree_node *> leftv;
    vector<binary_tree_node *> rightv;
    int left_depth = get_bintree_depth(root->left, leftv);
    int right_depth = get_bintree_depth(root->right, rightv);

    if (left_depth < right_depth)
    {
        binv.insert(binv.end(), rightv.begin(), rightv.end());
        return (right_depth + 1);
    }
    else
    {
        binv.insert(binv.end(), leftv.begin(), leftv.end());
        return (left_depth + 1);
    }
}

void print_vector(const vector<binary_tree_node *> &binv)
{
    for (vector<binary_tree_node *>::const_iterator iter=binv.begin(); iter!=binv.end(); ++iter)
    {
        cout << (*iter)->data << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    freopen("bintree_depth.in", "r", stdin);
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        vector<binary_tree_node *> binv;
        binary_tree_node *root = NULL;
        build_tree(root);
        cout << get_bintree_depth(root, binv) << endl;
        print_vector(binv);

    }
    fclose(stdin);
    return 0;
}
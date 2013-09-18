#include <iostream>
#include <map>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;

struct binary_tree_node
{
    int data;
    binary_tree_node *left;
    binary_tree_node *right;

    binary_tree_node() : data(0), left(NULL), right(NULL)
    {}

    friend bool operator<(binary_tree_node &lhs, binary_tree_node &rhs)
    {
        return lhs.data < rhs.data;
    }
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

int get_bintree_depth(binary_tree_node *root, map<binary_tree_node*, int> &depth_map)
{
    if (NULL == root)
    {
        return 0;
    }

    int left_depth = depth_map[root->left];
    int right_depth = depth_map[root->right];

    if (left_depth == 0)
    {
        left_depth = get_bintree_depth(root->left, depth_map);
        depth_map.insert(pair<binary_tree_node*, int>(root->left, left_depth));
    }

    if (right_depth == 0)
    {
        right_depth = get_bintree_depth(root->right, depth_map);
        depth_map.insert(pair<binary_tree_node*, int>(root->right, right_depth));
    }

    int root_depth = (left_depth > right_depth) ? (left_depth+1) : (right_depth+1);
    depth_map.insert(pair<binary_tree_node*, int>(root, root_depth));
    return root_depth;
}

bool is_balanced(binary_tree_node *root, map<binary_tree_node*, int> &depth_map)
{
    if (NULL == root)
    {
        return true;
    }

    int left_depth = get_bintree_depth(root->left, depth_map);
    int right_depth = get_bintree_depth(root->right, depth_map);
    int diff = left_depth - right_depth;

    if (diff<-1 || diff>1)
    {
        return false;
    }

    return (is_balanced(root->left, depth_map) && is_balanced(root->right, depth_map));
}

int main(int argc, char const *argv[])
{
    freopen("bintree_depth.in", "r", stdin);
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        map<binary_tree_node*, int> depth_map;
        binary_tree_node *root = NULL;
        build_tree(root);
        cout << std::boolalpha << is_balanced(root, depth_map) << endl;
    }
    fclose(stdin);
    return 0;
}
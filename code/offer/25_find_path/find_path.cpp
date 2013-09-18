#include <iostream>
#include <vector>
#include <iterator>
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

void pre_order(binary_tree_node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void find_path(binary_tree_node *root, int value, vector<int> &path, int &current_sum)
{
    current_sum += root->data;
    path.push_back(root->data);

    bool is_leaf = NULL==root->left && NULL==root->right;
    if (current_sum==value && is_leaf)
    {
        cout << "find a path: ";
        for (std::vector<int>::iterator iter = path.begin(); iter != path.end(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    // 如果不是叶子节点, 遍历左子树和右子树
    if (root->left != NULL)
    {
        find_path(root->left, value, path, current_sum);
    }

    if (root->right != NULL)
    {
        find_path(root->right, value, path, current_sum);
    }

    // 在遍历完左右子树回到父节点之前, 在路径上删除当前节点
    // 并在current_sum中减去当前节点的值
    current_sum -= root->data;
    path.pop_back();
}
void find_path_in_tree(binary_tree_node *root, int value)
{
    if (NULL == root)
    {
        cout << "empty tree!" << endl;
        return;
    }
    int current_sum = 0;
    vector<int> path;
    find_path(root, value, path, current_sum);
}

int main(int argc, char const *argv[])
{
    freopen("find_path.in", "r", stdin);
    freopen("find_path.out", "w", stdout);
    binary_tree_node *root = NULL;
    build_tree(root);
    cout << ">> pre_order: ";
    pre_order(root);
    int value;
    cout << endl;
    cout << "------------------------" << endl;
    cout << "input a sum to find: ";
    cin >> value;
    find_path_in_tree(root, value);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
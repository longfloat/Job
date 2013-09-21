#ifndef BIN_TREE_H
#define BIN_TREE_H

template <typename T>
struct bin_tree_node
{
    T data;
    bin_tree_node *left;
    bin_tree_node *right;
};

#endif
/**
* 实现函数complex_list_node* clone(complex_list_node *head)
* 复制一个复杂链表; 
* 在复杂链表中, 每个节点除了有一个next指针指向下一个节点外,
* 还有一个sibling指针指向链表中的任意节点或者NULL.
* 节点的结构定义:
* struct complex_list_node
* {
*     int data;
*     complex_list_node *next;
*     complex_list_node *sibling;
* }; 
*/

#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

struct complex_list_node
{
    int data;
    complex_list_node *next;
    complex_list_node *sibling;
};

void clone_nodes(complex_list_node *head)
{
    complex_list_node *node = head;
    while (node != NULL)
    {
        complex_list_node *cloned_node = new complex_list_node();
        cloned_node->data = node->data;
        cloned_node->next = node->next;
        cloned_node->sibling = NULL;

        node->next = cloned_node;
        node = cloned_node->next;
    }
}

void connect_sibling_nodes(complex_list_node *head)
{
    complex_list_node *node = head;
    while (node != NULL)
    {
        complex_list_node *cloned_node = node->next;

        if (node->sibling != NULL)
        {
            cloned_node->sibling = node->sibling->next;
        }
        node = cloned_node->next;
    }
}

complex_list_node* split_list(complex_list_node *head)
{
    complex_list_node *node = head;
    complex_list_node *cloned_head = NULL;
    complex_list_node *cloned_node = NULL;

    // 检测头指针是否为空
    if (node != NULL)
    {
        cloned_head = cloned_node = node->next;
        node->next = cloned_node->next;
        node = node->next;
    }

    while (node != NULL)
    {
        cloned_node->next = node->next;
        cloned_node = cloned_node->next;
        node->next = cloned_node->next;
        node = node->next;
    }

    return cloned_head;
}

complex_list_node* complex_list_clone(complex_list_node *head)
{
    clone_nodes(head);
    connect_sibling_nodes(head);
    return split_list(head);
}

complex_list_node* create_node(int data)
{
    complex_list_node *node = new complex_list_node();
    node->data = data;
    node->next = NULL;
    node->sibling = NULL;

    return node;
}

void build_list(complex_list_node *node, complex_list_node *next, complex_list_node *sibling)
{
    if (node != NULL)
    {
        node->next = next;
        node->sibling = sibling;
    }
}

void print_list(complex_list_node *head)
{
    cout << "(data, next, sibling)" << endl;
    complex_list_node *node = head;
    if (NULL == node)
    {
        cout << "(NULL, NULL, NULL)" << endl;
    }
    while (node != NULL)
    {
        cout << "(" << node->data << ", ";
        if (node->next != NULL)
            cout << node->next->data << ", ";
        else
            cout << "NULL, ";

        if (node->sibling != NULL)
            cout << node->sibling->data << ")";
        else
            cout << "NULL)";
        
        cout << " ";
        node = node->next;
    }
    cout << endl;
}

// ====================测试代码====================
void test(const char* test_name, complex_list_node* pHead)
{
    cout << "----------------------" << endl;
    if(test_name != NULL)
        cout << ">> " << test_name << " begins:" << endl;

    cout << "The original list is: ";
    print_list(pHead);

    complex_list_node* pClonedHead = complex_list_clone(pHead);

    cout << "The cloned list is: ";
    print_list(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void test1()
{
    complex_list_node* pNode1 = create_node(1);
    complex_list_node* pNode2 = create_node(2);
    complex_list_node* pNode3 = create_node(3);
    complex_list_node* pNode4 = create_node(4);
    complex_list_node* pNode5 = create_node(5);

    build_list(pNode1, pNode2, pNode3);
    build_list(pNode2, pNode3, pNode5);
    build_list(pNode3, pNode4, NULL);
    build_list(pNode4, pNode5, pNode2);

    test("test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void test2()
{
    complex_list_node* pNode1 = create_node(1);
    complex_list_node* pNode2 = create_node(2);
    complex_list_node* pNode3 = create_node(3);
    complex_list_node* pNode4 = create_node(4);
    complex_list_node* pNode5 = create_node(5);

    build_list(pNode1, pNode2, NULL);
    build_list(pNode2, pNode3, pNode5);
    build_list(pNode3, pNode4, pNode3);
    build_list(pNode4, pNode5, pNode2);

    test("test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void test3()
{
    complex_list_node* pNode1 = create_node(1);
    complex_list_node* pNode2 = create_node(2);
    complex_list_node* pNode3 = create_node(3);
    complex_list_node* pNode4 = create_node(4);
    complex_list_node* pNode5 = create_node(5);

    build_list(pNode1, pNode2, NULL);
    build_list(pNode2, pNode3, pNode4);
    build_list(pNode3, pNode4, NULL);
    build_list(pNode4, pNode5, pNode2);

    test("test3", pNode1);
}

// 只有一个结点
void test4()
{
    complex_list_node* pNode1 = create_node(1);
    build_list(pNode1, NULL, pNode1);

    test("test4", pNode1);
}

// 鲁棒性测试
void test5()
{
    test("test5", NULL);
}

int main(int argc, char const *argv[])
{
    freopen("complex_list_copy.out", "w", stdout);
    test1();
    test2();
    test3();
    test4();
    test5();
    fclose(stdout);
    return 0;
}
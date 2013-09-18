#include <iostream>
#include <cstdio>
using std::cin;
using std::cout;
using std::endl;

struct list_node
{
    int data;
    list_node *next;
};

void destroy_list(list_node *&head)
{
    if (head != NULL)
    {
        list_node *node = head->next;
        while (node != NULL)
        {
            head->next = node->next;
            delete node;
            node = head->next;
        }
    }
}

void create_list(list_node* &head)
{
    if (head != NULL)
    {
        destroy_list(head);
    }

    head = new list_node();
    head->data = -1;
    head->next = NULL;

    list_node *current = head;
    int data;
    while (cin >> data)
    {
        list_node *node = new list_node();
        node->data = data;
        node->next = NULL;
        current->next = node;
        current = current->next;
    }
}

void create_loop_list(list_node* &head)
{
    head = new list_node();
    head->data = -1;

    int data = 0, loop_data = 0;
    list_node *current = head;
    list_node *loop = NULL;

    cin >> loop_data;
    while (cin >> data)
    {
        list_node *node = new list_node();
        node->data = data;
        node->next = NULL;
        if (data == loop_data)
        {
            loop = node;
        }
        current->next = node;
        current = current->next;
    }
    current->next = loop;
}

/**
* 检测一个单链表是否存在环
* 设置两个指针, 从头节点开始向前走, 一个每次走一步, 一个每次走两步.
* 若两个指针相遇, 则链表存在环, 返回碰撞点;
* 否则如果当走得快的指针为NULL时, 链表没有环, 返回NULL.
*/
list_node* has_loop(list_node *head)
{
    if (NULL == head || NULL == head->next)
    {
        return NULL;
    }

    list_node *slow = head;
    list_node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

/**
* 寻找带环单链表环的入口
* 从检测是否存在环的碰撞点开始,
* 头节点到环入口节点的距离=碰撞点到环入口节点的距离
*/
list_node* loop_entry(list_node *head)
{
    list_node *q = has_loop(head);
    if (NULL == q)
    {
        return NULL;
    }

    list_node *p = head;
    while (p != q)
    {
        p = p->next;
        q = q->next;
    }

    return p;
}

/**
* 头节点到环入口节点的距离=碰撞点到环入口节点的距离
*/
size_t head_entry_length(list_node *head)
{
    list_node *entry = loop_entry(head);
    if (NULL == entry)
    {
        return 0;
    }

    size_t length = 0;
    list_node *p = head;
    while (p != entry)
    {
        ++length;
        p = p->next;
    }

    return length;
}

/**
* 获取带环单链表环的长度
* 记录下判断链表是否存在环时的碰撞点,
* slow和fast从该点开始, 再次碰撞所走过的操作数就是环的长度
*/
size_t loop_length(list_node *head)
{
    list_node *collision = has_loop(head);
    if (NULL == collision)
    {
        return 0;
    }

    list_node *slow = collision;
    list_node *fast = collision;
    size_t length = 0;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
        ++length;
    }while (slow != fast);

    return length;
}

size_t loop_list_length(list_node *head)
{
    return head_entry_length(head) + loop_length(head);
}

void print_loop_list(list_node *head)
{
    if (NULL == head || NULL==head->next)
    {
        cout << "empty list!" << endl;
        return;
    }

    list_node *entry = loop_entry(head);
    bool flag = false;
    list_node *p = head->next;
    while (true)
    {
        if (p == entry)
        {
            if (!flag)
            {
                flag = true;
            }
            else
            {
                cout << p->data;
                break;
            }
        }
        cout << p->data << "->";
        p = p->next;
    }
    cout << endl;
}

bool has_intersect_noloop(list_node *head1, list_node *head2)
{
    if (NULL==head1 || NULL==head2)
    {
        return false;
    }

    list_node *p = head1;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head2;

    list_node *collision = has_loop(head1);
    p->next = NULL;
    return ((NULL==collision) ? false : true);
}

bool has_intersect_noloop2(list_node *head1, list_node *head2)
{
    if (NULL==head1 || NULL==head2)
    {
        return false;
    }

    list_node *p = head1;
    while (p->next != NULL)
    {
        p = p->next;
    }

    list_node *q = head2;
    while (q->next != NULL)
    {
        q = q->next;
    }
    return p==q;
}

bool has_intersect_loop(list_node *head1, list_node *collision1, list_node *head2, list_node *collision2)
{
    list_node *p = collision2;
    while (p != collision1)
    {
        p = p->next;
        if (p == collision2)
        {
            return true;
        }
    }

    return false;
}

bool check_intersect(list_node *head1, list_node *head2)
{
    list_node *collision1 = has_loop(head1);
    list_node *collision2 = has_loop(head2);

    if (NULL==collision1 && NULL==collision2)
    {
        return has_intersect_noloop(head1, head2);
    }
    else if (collision1!=NULL && collision2!=NULL)
    {
        return has_intersect_loop(head1, collision1, head2, collision2);
    }
    else
        return false;
}

list_node* first_inrsect_node_noloop(list_node *head1, list_node *head2)
{
    if (NULL==head1 || NULL==head2)
    {
        return NULL;
    }

    list_node *p = head1;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head2;
    return loop_entry(head1);
}

list_node* first_inrsect_node_loop(list_node *head1, list_node *head2)
{
    size_t length1 = loop_list_length(head1);
    size_t length2 = loop_list_length(head2);
    size_t diff = 0;
    list_node *p = NULL;
    list_node *q = NULL;
    if (length1 > length2)
    {
        diff = length1 - length2;
        p = head1;
        q = head2;
    }
    else
    {
        diff = length2 - length1;
        p = head2;
        q = head1;
    }

    for (size_t i = 0; i < diff; ++i)
    {
        p = p->next;
    }

    while (p != q)
    {
        p = p->next;
        q = q->next;
    }

    return p;
}

list_node* first_inrsect_node(list_node *head1, list_node *head2)
{
    list_node *collision1 = has_loop(head1);
    list_node *collision2 = has_loop(head2);

    if (NULL==collision1 && NULL==collision2)
    {
        return first_inrsect_node_noloop(head1, head2);
    }
    else if (collision1!=NULL && collision2!=NULL)
    {
        return first_inrsect_node_loop(head1, head2);
    }
    else
        return NULL;
}

int main(int argc, char const *argv[])
{
    freopen("list_intersect.in", "r", stdin);
    list_node *head = NULL;
    create_loop_list(head);
    cout << std::boolalpha;
    cout << "the list: ";
    print_loop_list(head);
    list_node *collision = has_loop(head);
    cout << "is the list has loop? " << ((NULL==collision) ? false : true) << endl;
    if (collision != NULL)
    {
        cout << "the loop entry of the list: " << loop_entry(head)->data << endl;
        cout << "the length of the loop: " << loop_length(head) << endl;
        cout << "the length of the list: " << loop_list_length(head) << endl;
    }

    fclose(stdin);
    return 0;
}
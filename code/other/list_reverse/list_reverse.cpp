/**
 * 局部反转链表
 * 1->2->3->4->5->6->7->8->9->10
 * reverse 3
 * 3->2->1->6->5->4->9->8->7->10
 * ---------------------
 * 1->2->3->4->5->6->7->8->9->10
 * reverse 6
 * 6->5->4->3->2->1->7->8->9->10
 * ---------------------
 * 1->2->3->4->5
 * reverse 7
 * 5->4->3->2->1
 * ---------------------
 * 1->2->3->4->5->6
 * reverse 0
 * 1->2->3->4->5->6
 * ---------------------
 * 1->2->3->4->5->6->7->8
 * reverse 2
 * 2->1->4->3->6->5->8->7
 * ---------------------
 * 1->2->3->4
 * reverse 1
 * 1->2->3->4
 * ---------------------
 * */
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
    int length, data;
    cin >> length;
    for (int i=0; i<length; ++i)
    {
        cin >> data;
        list_node *node = new list_node();
        node->data = data;
        node->next = NULL;
        current->next = node;
        current = current->next;
    }
}

void reverse(list_node* &start, list_node* &end)
{
    if (NULL==start || NULL==end)
    {
        return;
    }

    list_node *prev = NULL;
    list_node *curr = start;

    while (curr != end)
    {
        list_node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    end->next = prev;
    start->next = NULL;
}

void reverse_k(list_node *&head, int k)
{
    if (NULL==head || NULL==head->next || k<2)
    {
        return;
    }

    int count = 0;
    list_node *node = head->next;
    while (node != NULL)
    {
        ++count;
        node = node->next;
    }

    if (k > count)
    {
        k = count;
    }

    // start记录反转段的开始
    list_node *start = head->next;
    // end记录反转段结束位置的下一个位置
    list_node *end = head->next;
    // prev记录本次反转后本段的末尾位置
    // 用于将本次反转和下次反转连接起来
    list_node *prev = head->next;
    node = head->next;
    bool first = true;
    while (end != NULL)
    {
        count = 0;
        list_node *tmp = end;
        while (end!=NULL && count<k)
        {
            ++count;
            tmp = end;
            end = end->next;
        }

        if (count == k)
        {
            reverse(start, tmp);
            if (first)
            {
                // 处理头节点
                head->next = tmp;
                first = false;
            }
            else
            {
                // 将上次的反转段和本次反转后的段连接起来
                prev->next = tmp;
            }
            // 准备下一次反转
            start->next = end;
            prev = start;
            start = end;
        }
        else
        {
            // count!=k表明剩余的节点个数已不足k个
            // 无需反转, 直接退出
            break;
            first = false;
        }
    }
}

void print_list(list_node *head)
{
    if (NULL==head)
    {
        cout << "empty list!" << endl;
        return;
    }
    list_node *node = head->next;
    while (node->next != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << node->data << endl;
}


/**
 * INPUT:
 * 输入数据第一行为一个整数n, 表示测试用例组数;
 * 接下来是n组测试数据, 每组测试数据包含3行;
 *   第一行为链表节点个数m,
 *   第二行为m个节点,
 *   第三行为需要局部反转的节点个数k.
 *
 * OUTPUT:
 * 输出数据包含多行
 * 对应于每组输入, 输出包含4行:
 *   第一行为原始链表的输出,各节点之间用->连接,
 *   第二行为reverse k, 其中k为局部反转链表数目,
 *   第三行为反转后的链表的输出, 输出方式同原始链表;
 *   第四行为分割线
 * */
int main(int argc, const char *argv[])
{
    freopen("list_reverse.in", "r", stdin);
    int n = 0, k = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        list_node *head = NULL;
        create_list(head);
        print_list(head);
        cin >> k;
        reverse_k(head, k);
        cout << "reverse " << k << endl;
        print_list(head);
        destroy_list(head);
        cout << "---------------------" << endl;
    }

    fclose(stdin);
    return 0;
}

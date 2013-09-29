/**
* 2014 Microsoft capmus recruit writing test
* Programming Questions
* 
* Given a singly linked list L: (L0, L1, L2, ..., Ln-1, Ln).
* Write a program to reorder it so that it becomes
* (L0, Ln, L1, Ln-1, L2, Ln-2, ...).
* 
* struct node
* {
* 	int value;
* 	node *next;
* };
* 
* Notes:
* 1) Space complexity should be O(1);
* 2) Only the ".next" field of a node is modifiable.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

struct node
{
	int value;
	node *next;

	node(int _value = 0, node *_next = NULL) : value(_value), next(_next)
	{}
};

void create_list(node* &head, int n)
{
	if (NULL == head)
		head = new node();

	int value = 0;
	node *p = head;
	for (int i = 0; i < n; ++i)
	{
		cin >> value;
		if (i > 0)
		{
			node *q = new node(value);
			p->next = q;
			p = p->next;
		}
		else
		{			
			head->value = value;
		}
	}
}

void print_list(const node *head)
{
	const node *p = head;
	while (p != NULL)
	{
		cout << p->value << " ";
		p = p->next;
	}

	cout << endl;
}

void delete_list(node* &head)
{
	if (NULL == head)
		return;

	node *p = head->next;
	node *q = NULL;

	while (p != NULL)
	{
		q = p->next;
		head->next = q;
		delete p;
		p = q;
	}

	delete head;
}

/**
* reverse a single list from begin to end.
*/
node* reverse(node *head)
{
	if (NULL==head || NULL==head->next)
		return head;
	node *r_head = NULL;
	node *pre = NULL;
	node *cur = head;
	node *next = NULL;

	while (cur != NULL)
	{
		if (NULL == cur->next)
			r_head = cur;

		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}

	return r_head;
}

void reorder(node *head, int n)
{
	if (n < 0 || NULL==head || NULL==head->next)
		return;

	node *p = head;
	node *q = NULL;

	int end = 0;
	// set half position according the parity of list's size
	if ((n & 1) == 0)
		end = n / 2;
	else
		end = n / 2 + 1;
	
	// find the half position of the list
	for (int i = 0; i < end; ++i)
	{
		q = p;
		p = p->next;
	}

	// reverse the latter
	node *half_head = reverse(p);
	q->next = half_head;

	cout << "after reverse:\t";
	print_list(head);

	node *np = NULL;
	node *nq = NULL;
	p = head;
	q = half_head;

	// ajust the next field of node simultaneously from list head and half head
	while ((p != NULL) && (p->next != half_head) && (q != NULL))
	{
		np = p->next;
		p->next = q;

		nq = q->next;
		q->next = np;

		p = np;
		q = nq;
	}
	
	if (p != NULL)
		p->next = q;
}

int main(int argc, const char *argv[])
{
	freopen("reorder.in", "r", stdin);
	freopen("reorder.out", "w", stdout);

	int n;
	while (cin >> n)
	{
		cout << "--------------------------------------" << endl;
		node *head = NULL;
		create_list(head, n);
		cout << "before reorder:\t";
		print_list(head);
		reorder(head, n);
		cout << "after reorder:\t";
		print_list(head);
		delete_list(head);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
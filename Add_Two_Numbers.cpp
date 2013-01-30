#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

int AddDigit( int a, int b, int& carry )
{
	int ret = a + b + carry;
	if( ret >= 10 )
	{
		ret = ret % 10;
		carry = 1;
		return ret;
	}
	else if( ret < 10 )
	{
		carry = 0;
		return ret;
	}
}

ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 )
{
	int carry = 0;
	ListNode* head = NULL;
	ListNode* pre = NULL;
	ListNode* pnode = NULL;
	while( l1 != NULL && l2 != NULL )
	{
		int tmpval = AddDigit( l1->val, l2->val, carry );
		pnode = new ListNode( tmpval );
		if( head == NULL )
		{
			head = pnode;
			pre = pnode;
		}
		else if( head != NULL )
		{
			pre->next = pnode;
			pre = pnode;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	ListNode* rest = NULL;
	if( l1 != NULL ) rest = l1;
	else if( l2 != NULL ) rest = l2;
	else 
	{
		if( carry == 1 )
		{
			pnode = new ListNode( 1 );
			pre->next = pnode;
		}
		return head;
	}
	
	while( rest != NULL )
	{
		int tmpval = AddDigit( rest->val, 0, carry );
		pnode = new ListNode( tmpval );
		pre->next = pnode;
		pre = pnode;
		rest = rest->next;
	}
	if( carry == 1 )
	{
		pnode = new ListNode( 1 );
		pre->next = pnode;
	}
	return head;
}

void output( ListNode* head )
{
	ListNode* pnode = head;
	while( pnode != NULL )
	{
		cout << pnode->val;
		pnode = pnode->next;
	}
	cout << endl;
}

ListNode* CreateList( int n )
{
	ListNode* head = NULL;
	ListNode* pre = NULL;
	int digit;
	while( n != 0 )
	{
		digit = n % 10;
		n = n / 10;
		ListNode* pnode = new ListNode(digit);
		if( head == NULL )
		{
			head = pnode;
			pre = pnode;
		}
		else if( head != NULL )
		{
			pre->next = pnode;
			pre = pnode;
		}
	}
	return head;
}

int main()
{
	ListNode* head1 = CreateList(5);
	ListNode* head2 = CreateList(5);
	ListNode* head3 = addTwoNumbers( head1, head2 );
	output(head3);
	return 0;
}

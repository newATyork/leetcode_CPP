#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( NULL == l1 && NULL == l2 )
			return NULL;
		ListNode* head = NULL;
		ListNode* pre = NULL;
		while( l1 != NULL && l2 != NULL )
		{
			ListNode* pnode;
			if( l1->val <= l2->val )
			{
				pnode = l1;
				l1 = l1->next;
			}
			else if( l1->val > l2->val )
			{
				pnode = l2;
				l2 = l2->next;
			}
			if( pre == NULL )
				head = pnode;
			else
				pre->next = pnode;
			pre = pnode;
		}
		ListNode* nextnode = (NULL == l1) ? l2 : l1;
		if( pre == NULL )
			head = nextnode;
		else
			pre->next = nextnode;
		return head;
	}
};


int main()
{
	return 0;
}

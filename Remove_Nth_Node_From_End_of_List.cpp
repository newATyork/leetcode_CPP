#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ListNode* tmphead = new ListNode(0);
		tmphead->next = head;
		ListNode* slowp = tmphead;
		ListNode* quickp = head;
		int dist = 1;
		while( quickp->next != NULL )
		{
			if( dist != n )
				dist++;
			else if( dist == n )
				slowp = slowp->next;
			quickp = quickp->next;
		}
		ListNode* toDel = slowp->next;
		slowp->next = toDel->next;
		delete toDel;
		return tmphead->next;
    }
};

ListNode* MakeList()
{
	ListNode* head = NULL;
	ListNode* pre = NULL;
	for( int i = 1 ; i <= 10; ++i )
	{
		ListNode* newnode = new ListNode(i);
		if( pre == NULL )
		{
			pre = newnode;
			head = newnode;
		}
		else
		{
			pre->next = newnode;
			pre = newnode;
		}
	}
	return head;
}

int main()
{
	Solution so;
	ListNode* head = MakeList();
	so.output( head );
	so.output(so.removeNthFromEnd( head, 5 ));
	return 0;
}

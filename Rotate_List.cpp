// It's almost same as the problem "Remove Nth Node From End of List"
// Just link the tail to the head, then set the Nth node as new head.

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( NULL == head || k == 0 )
			return head;
		int len = 0;
		ListNode* cur = head;
		while( NULL != cur )
		{
			len++;
			cur = cur->next;
		}
		k = k % len;
		if( 0 == k ) return head;
		ListNode* tmphead = new ListNode(0);
		tmphead->next = head;
		ListNode* slowp = tmphead;
		ListNode* quickp = head;
		int dist = 1;
		while( NULL != quickp->next )
		{
			if( dist != k ) 
				dist++;
			else if( dist == k )
				slowp = slowp->next;
			quickp = quickp->next;
		}
		tmphead = slowp->next;
		quickp->next = head;
		slowp->next = NULL;
		return tmphead;
	}
};


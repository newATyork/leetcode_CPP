/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		ListNode* pre = NULL;
		ListNode* post = NULL;
		int dist = 0;
		ListNode* tmphead = new ListNode(0);
		tmphead->next = head;
		ListNode* cur = tmphead;
		while( cur != NULL )
		{
			if( dist == m - 1 ) 
				pre = cur;
			else if( dist == n ) 
				post = cur->next;
			dist++;
			cur = cur->next;
		}
		head = pre->next;
		ListNode* tail = 
	}
};


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
	ListNode *deleteDuplicates(ListNode *head) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( NULL == head )
			return NULL;
		ListNode* pnode = head->next;
		ListNode* pre = head;
		int preval = head->val;
		while( pnode != NULL )
		{
			if( pnode->val != preval )
			{
				pre->next = pnode;
				pre = pnode;
				preval = pnode->val;
			}
			pnode = pnode->next;
		}
		pre->next = NULL;
		return head;
	}
};


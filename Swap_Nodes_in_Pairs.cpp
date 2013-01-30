class Solution {
public:
	ListNode* swapPairs( ListNode* head )
	{
		if( head == NULL ) return NULL;
		if( head->next == NULL ) return head;
		ListNode* newhead = head->next;
		ListNode* pNode = head;
		ListNode* preNode = NULL;
		ListNode* postNode = NULL;
		while( pNode != NULL )
		{
			postNode = pNode->next;
			if( postNode == NULL ) break;
			if( preNode != NULL )
				preNode->next = postNode;
			pNode->next = postNode->next;
			postNode->next = pNode;
			preNode = pNode;
			pNode = pNode->next;
		}
		return newhead;
	}
};

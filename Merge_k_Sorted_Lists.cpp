#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( lists.size() == 0 )
			return NULL;
		ListNode* head = NULL;
		ListNode* pre = NULL;
		ListNode* index[lists.size()];
		int rec;
		for( int i = 0; i < lists.size(); ++i )
			index[i] = lists[i];
		while( true )
		{
			int min = 0x7FFFFFFF;
			ListNode* minnode = NULL;
			for( int i = 0; i < lists.size(); ++i )
			{
				if( index[i] != NULL )
				{
					if( index[i]->val < min )
					{
						min = index[i]->val;
						minnode = index[i];
						rec = i;
					}
				}
			}
			if( minnode == NULL )
				break;
			else if( pre == NULL )
				head = minnode;
			else if( pre != NULL )
				pre->next = minnode;
			pre = minnode;
			index[rec] = index[rec]->next;
		}
		return head;
    }
};

int main()
{
	Solution so;
	ListNode* node = NULL;
	vector<ListNode*> vec;
	vec.push_back(node);
	so.mergeKLists(vec);
	return 0;
}

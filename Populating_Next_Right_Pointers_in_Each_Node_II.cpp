
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( NULL == root )
			return;
		vector<TreeLinkNode*> vec;
		vec.push_back( root );
		int cur = 0;
		int last = 1;
		while( cur != vec.size() )
		{
			last = vec.size();
			while( cur < last )
			{
				if( cur == last - 1 )
					vec[cur]->next = NULL;
				else
					vec[cur]->next = vec[cur+1];
				if( NULL != vec[cur]->left )
					vec.push_back( vec[cur]->left );
				if( NULL != vec[cur]->right )
					vec.push_back( vec[cur]->right );
				cur++;
			}
		}
	}
};


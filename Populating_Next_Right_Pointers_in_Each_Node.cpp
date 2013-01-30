
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
		while( !vec.empty() )
		{
			vector<TreeLinkNode*> cur = vec;
			vec.clear();
			for( int i = 0; i < cur.size(); ++i )
			{
				if( i == cur.size() - 1 )
					cur[i]->next = NULL;
				else
					cur[i]->next = cur[i+1];
				if( NULL != cur[i]->left )
					vec.push_back( cur[i]->left );
				if( NULL != cur[i]->right )
					vec.push_back( cur[i]->right );
			}
		}
	}
};


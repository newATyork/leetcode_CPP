
//    almost same as Binary Tree Level Order Traversal
//    if( index++ % 2 == 1 ) reverse(...)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > result;
		if( root == NULL )
			return result;
		vector<TreeNode*> q;
		q.push_back( root );
		int index = 0;
		while( !q.empty() )
		{
			vector<TreeNode*> cur = q;
			q.clear();
			vector<int> level;
			for( int i = 0; i < cur.size(); ++i )
			{
				level.push_back( cur[i]->val );
				if( cur[i]->left != NULL ) 
					q.push_back( cur[i]->left ); 
				if( cur[i]->right != NULL ) 
					q.push_back( cur[i]->right ); 
			}
			if( index++ % 2 == 1 )
				reverse( level.begin(), level.end() );
			result.push_back(level);
		}
		return result;
	}
};




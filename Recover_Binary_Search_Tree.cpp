class Solution {
public:
	void recoverTree(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<TreeNode*> vec;
		inorder( root, vec );
		TreeNode* pnode1 = NULL;
		TreeNode* pnode2 = NULL;
		for( int i = 0; i < vec.size() - 1; ++i )
		{
			if( vec[i]->val > vec[i+1]->val )
			{
				pnode1 = vec[i];
				break;
			}
		}
		for( int i = vec.size() - 1; i > 0; --i )
		{
			if( vec[i]->val < vec[i-1]->val )
			{
				pnode2 = vec[i];
				break;
			}
		}
		swap( pnode1->val, pnode2->val );
		return;
	}
	void inorder( TreeNode* root, vector<TreeNode*>& vec )
	{
		if( NULL == root ) return;
		inorder( root->left, vec );
		vec.push_back( root );
		inorder( root->right, vec );
	}
};


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
	bool isSymmetric(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( NULL == root ) return true;
		return isSymmetric( root->left, root->right );
	}
	bool isSymmetric( TreeNode* left, TreeNode* right )
	{
		if( NULL == left && NULL == right ) return true;
		if( NULL == left && NULL != right ) return false;
		if( NULL != left && NULL == right ) return false;
		if( left->val != right->val ) return false;
		bool flag1 = isSymmetric( left->right, right->left );
		bool flag2 = isSymmetric( left->left, right->right );
		return flag1 && flag2;
	}
};


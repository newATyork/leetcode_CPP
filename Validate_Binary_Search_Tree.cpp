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
	bool isValidBST(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		return isValidBST( root, INT_MIN, INT_MAX );
	}
	bool isValidBST( TreeNode* root, int min, int max )
	{
		if( root == NULL ) return true;
		if( root->val <= min ) return false;
		if( root->val >= max ) return false;
		bool left = isValidBST( root->left, min, root->val );
		bool right = isValidBST( root->right, root->val, max );
		return left && right;
	}
};

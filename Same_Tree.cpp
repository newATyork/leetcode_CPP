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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( NULL == p && NULL == q ) return true;
		if( NULL == p && NULL != q ) return false;
		if( NULL != p && NULL == q ) return false;
		if( p->val != q->val ) return false;
		bool left = isSameTree( p->left, q->left );
		bool right = isSameTree( p->right, q->right );
		return left && right;
	}
};


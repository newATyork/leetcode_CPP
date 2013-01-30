class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		TreeNode* root = CreateBST( num, 0, num.size() - 1 );
		return root;
	}
	TreeNode* CreateBST( vector<int>& num, int low, int high )
	{
		if( low > high ) return NULL;
		int mid = ( low + high ) / 2;
		TreeNode* root = new TreeNode( num[mid] );
		root->left = CreateBST( num, low, mid - 1 );
		root->right = CreateBST( num, mid + 1, high );
		return root;
	}
};

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	void flatten(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if( root == NULL )  
			return;  
		TreeNode* left = root->left;  
		TreeNode* right = root->right;  
		flatten( left );  
		flatten( right );  
		root->left = NULL;  
		root->right = left;  
		TreeNode* rightmost = root;  
		while( rightmost->right != NULL )  
			rightmost = rightmost->right;  
		rightmost->right = right;  	
	}
};

TreeNode* CreateBT( int* arr, int low, int high )
{
	if( low > high ) return NULL;
	int mid = ( low + high ) / 2;
	TreeNode* root = new TreeNode( arr[mid] );
	root->left = CreateBT( arr, low, mid - 1 );
	root->right = CreateBT( arr, mid + 1, high );
	return root;
}

void levelorder( TreeNode* root )
{
	vector<TreeNode*> q;
	q.push_back( root );
	while( !q.empty() )
	{
		vector<TreeNode*> cur = q;
		q.clear();
		for( int i = 0; i < cur.size(); ++i )
		{	
			cout << cur[i]->val << " ";
			if( cur[i]->left ) q.push_back( cur[i]->left );
			if( cur[i]->right ) q.push_back( cur[i]->right );
		}
		cout << endl;
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	TreeNode* root = CreateBT( arr, 0, len - 1 );
	Solution so;
	cout << "!!!!!" << endl;
	so.flatten( root );
	levelorder( root );
	return 0;
}

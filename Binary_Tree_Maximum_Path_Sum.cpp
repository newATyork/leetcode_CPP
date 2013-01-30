
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxsum = 0;

int maxSumToNode( TreeNode* root )
{
	if( root == NULL ) return 0;
	int left = maxSumToNode( root->left );
	int right = maxSumToNode( root->right );

}


void maxPathSum( TreeNode *root, int& maxsum )
{
	if( root == NULL ) return ;
	int leftsub = maxSumToNode( root->left );
	int rightsub = maxSumToNode( root->right );
	if( leftsub + rightsub + (root->val) > maxsum )
	{
		maxsum = leftsub + rightsub + root->val ;
		return ;
	}
	maxPathSum( root->left, maxsum );
	maxPathSum( root->right, maxsum );
}


TreeNode* CreateTree( int* arr, int low, int high )
{
	if( low > high ) return NULL;
	int mid = ( low + high ) / 2;
	TreeNode* root = new TreeNode( arr[mid] );
	root->left = CreateTree( arr, low, mid - 1 );
	root->right = CreateTree( arr, mid + 1, high );
	return root;
}

void levelOrder( TreeNode* root )
{
	vector<TreeNode*> q;
	q.push_back( root );
	int index = 1;
	while( !q.empty() )
	{
		cout << "level " << index++ <<" : ";
		vector<TreeNode*> cur = q;
		q.clear();
		for( int i = 0; i < cur.size(); ++i )
		{
			cout << cur[i]->val << " ";
			if( cur[i]->left != NULL )
				q.push_back( cur[i]->left );
			if( cur[i]->right != NULL )
				q.push_back( cur[i]->right );
		}
		cout << endl;
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr1[] = { -2, 1 };
	int len = sizeof(arr1) / sizeof(arr[0]);
	TreeNode* root = CreateTree( arr1, 0, len - 1 );
	levelOrder( root );
//	maxPathSum( root );
//	cout << maxsum << endl;
	cout << maxSumToNode( root ) << endl;
	return 0;
}


class Solution {
public:
	int maxPathSum( TreeNode* root, int& maxsum )
	{
		if( root == NULL ) return 0;
		int left = maxPathSum( root->left, maxsum );
		int right = maxPathSum( root->right, maxsum );
		int localmax = root->val;
		if( left > 0 ) localmax += left;
		if( right > 0 ) localmax += right;
		maxsum = maxsum > localmax ? maxsum : localmax ;
		return max( root->val, max( root->val + left, root->val + right ) );
	}

	int maxPathSum(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int tmp_maxsum = root->val;
		int maxsum = maxPathSum( root, tmp_maxsum );
		return tmp_maxsum > maxsum ? tmp_maxsum : maxsum;
	}
};

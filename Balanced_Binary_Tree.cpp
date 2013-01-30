#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int n ) : val(n), left(NULL), right(NULL) {}
};

bool isBalanced( TreeNode *root )
{
	int ret = isBanlancedCore( root );
	if( ret == -1 ) return false;
	return true;
}

int isBalancedCore( TreeNode* root )
{
	if( root == NULL )
		return 0;
	int left = isBalancedCore( root->left );
	int right = isBalancedCore( root->right );
	int max = left > right ? left : right;
	int min = left < right ? left : right;
	if( max - min > 1 )
		return -1;
	return ( max + 1 );
}

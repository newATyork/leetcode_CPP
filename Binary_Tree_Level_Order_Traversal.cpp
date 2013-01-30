#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;                                     
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode *root)
{
	vector<vector<int> > result;
	if( root == NULL )
		return result;
	vector<TreeNode*> q;
	q.push_back( root );
	while( !q.empty() )
	{
		vector<TreeNode*> cur = q;
		q.clear();
		vector<int> level;
		for( int i = 0; i < cur.size(); ++i )
		{
			cout << cur[i]->val << " ";
			level.push_back( cur[i]->val );
			if( cur[i]->left != NULL ) 
				q.push_back( cur[i]->left ); 
			if( cur[i]->right != NULL ) 
				q.push_back( cur[i]->right ); 
		}
		result.push_back(level);
		level.clear();
	}
	return result;
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

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int len = sizeof(arr) / sizeof(arr[0]);
	TreeNode* head = CreateTree( arr, 0, len - 1 );
	CreateTree( arr, 0, len - 1 );
//	vector< vector<int> > vec = levelOrder( head );
	levelOrder( head );
	return 0;
}

#include <iostream>
using namespace std;

Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector< vector<int> > result;
		vector<int> rec;
		pathSumCore( root, sum, result, rec );
		return result;
	}
	void pathSumCore( TreeNode* root, int sum, vector< vector<int> >& result, vector<int>& rec )
	{
		if( NULL == root )
			return;
		if( NULL == root->left && NULL == root->right )
		{
			if( root->val == sum )
			{
		 		rec.push_back( root->val );
				result.push_back( rec );
				rec.pop_back();
				return;
			}
		}
		rec.push_back( root->val );
		pathSumCore( root->left, sum - root->val, result, rec );
		pathSumCore( root->right, sum - root->val, result, rec );
		rec.pop_back();	
	}
};


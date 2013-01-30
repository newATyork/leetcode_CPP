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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( NULL == root)
            return false;
        if( NULL == root->left && NULL == root->right )
            return root->val == sum;
        bool left = hasPathSum( root->left, sum - root->val );
		bool right = hasPathSum( root->right, sum - root->val );
		return left || right;
    }
};


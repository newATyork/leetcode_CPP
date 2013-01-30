class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL )
            return 0;
        int left = maxDepth( root->left );
        int right = maxDepth( root->right );
        int max = left > right ? left : right;
        return max+1;
    }
};


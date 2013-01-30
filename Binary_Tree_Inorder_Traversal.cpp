class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec;
        inorderTree( root, vec );
        return vec;
    }
    void inorderTree( TreeNode* root, vector<int>& vec )
    {
        if( root == NULL )
            return;
        inorderTree( root->left, vec );
        vec.push_back( root->val );
        inorderTree( root->right, vec );
    }
};

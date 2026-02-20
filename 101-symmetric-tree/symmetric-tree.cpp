class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both are null
        if (left == nullptr && right == nullptr)
            return true;
        
        // If one is null
        if (left == nullptr || right == nullptr)
            return false;
        
        // Check values and mirror structure
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return isMirror(root->left, root->right);
    }
};

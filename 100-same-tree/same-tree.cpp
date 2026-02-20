class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both nodes are null
        if (p == nullptr && q == nullptr)
            return true;
        
        // Case 2: one is null and the other is not
        if (p == nullptr || q == nullptr)
            return false;
        
        // Case 3: values are different
        if (p->val != q->val)
            return false;
        
        // Case 4: check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

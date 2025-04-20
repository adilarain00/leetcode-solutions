class Solution {
public:
    bool bst(TreeNode* root, long left, long right) {
        if (!root)
            return true;
        if (!(root->val > left && root->val < right))
            return false;
        return (bst(root->left, left, root->val) &&
                bst(root->right, root->val, right));
    }
    bool isValidBST(TreeNode* root) {
        long left = LONG_MIN;
        long right = LONG_MAX;
        return bst(root, left, right);
    }
};
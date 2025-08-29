class Solution {
    vector<int> res;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }

private:
    void inorder(TreeNode* node) {
        if (!node) {
            return;
        }
        inorder(node->left);
        res.push_back(node->val);
        inorder(node->right);
    }
};
class Solution {
    vector<int> res;

public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }

private:
    void preorder(TreeNode* node) {
        if (!node)
            return;

        res.push_back(node->val);
        preorder(node->left);
        preorder(node->right);
    }
};

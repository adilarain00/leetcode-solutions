class Solution {
    int diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }

private:
    int depth(TreeNode* node) {
        if (!node)
            return 0;

        int left = depth(node->left);
        int right = depth(node->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }
};

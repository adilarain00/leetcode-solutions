class Solution {
public:
    int max_diameter = 0;

    int height(TreeNode* node) {
        if (!node)
            return 0;
        int left = height(node->left);
        int right = height(node->right);
        max_diameter = max(max_diameter, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return max_diameter;
    }
};
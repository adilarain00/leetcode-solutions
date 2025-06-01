class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode* node, int& res) {
        if (!node) {
            return 0;
        }

        int leftSum = max(0, dfs(node->left, res));
        int rightSum = max(0, dfs(node->right, res));

        res = max(res, leftSum + rightSum + node->val);

        return max(leftSum, rightSum) + node->val;
    }
};
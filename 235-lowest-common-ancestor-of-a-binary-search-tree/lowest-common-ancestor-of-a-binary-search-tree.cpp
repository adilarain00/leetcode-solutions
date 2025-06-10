class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low = min(p->val, q->val);
        int high = max(p->val, q->val);

        while (root != NULL) {
            if (high < root->val)
                root = root->left;
            else if (low > root->val)
                root = root->right;
            else {
                return root;
            }
        }

        return NULL;
    }
};
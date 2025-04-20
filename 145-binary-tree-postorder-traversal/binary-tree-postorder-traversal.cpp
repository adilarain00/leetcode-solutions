class Solution {
    void postorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        postorder(root->left, arr);
        postorder(root->right, arr);
        arr.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postorder(root, arr);
        return arr;
    }
};
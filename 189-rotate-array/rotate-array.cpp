class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Reverse the entire array.
        reverse(nums.begin(), nums.end());
        
        // Step 2: Reverse the first k elements.
        reverse(nums.begin(), nums.begin() + k % n);
        
        // Step 3: Reverse the remaining elements.
        reverse(nums.begin() + k % n, nums.end());
    }
};

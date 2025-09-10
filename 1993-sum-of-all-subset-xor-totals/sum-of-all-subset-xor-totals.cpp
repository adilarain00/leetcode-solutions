class Solution {
public:
    int subsetXORSum(vector<int>& nums) { 
        return dfs(nums, 0, 0); 
    }

    int dfs(vector<int>& nums, int idx, int currXor) {
        if (idx == nums.size()) {
            return currXor;
        }

        int include = dfs(nums, idx + 1, currXor ^ nums[idx]);
        int exclude = dfs(nums, idx + 1, currXor);
        return include + exclude;
    }
};

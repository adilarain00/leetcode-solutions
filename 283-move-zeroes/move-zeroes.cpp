class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero = 0; // Pointer for non-zero elements

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap non-zero element with the element at `nonzero`
                swap(nums[i], nums[nonzero]);
                nonzero++; // Move the nonzero pointer
            }
        }
    }
};
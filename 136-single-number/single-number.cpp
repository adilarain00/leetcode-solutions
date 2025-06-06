class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            number = number ^ nums[i];
        }
        return number;
    }
};
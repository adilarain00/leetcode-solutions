class Solution {
public:
    int getmax(int start, vector<int>& v, int end) {
        int prev = 0;
        int prev2 = 0;
        for (int i = start; i <= end; i++) {
            int take = v[i];
            if (i > 1)
                take += prev2;
            int ntake = prev;

            int temp = max(take, ntake);
            prev2 = prev;
            prev = temp;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        return max(getmax(0, nums, n - 2), getmax(1, nums, n - 1));
    }
};
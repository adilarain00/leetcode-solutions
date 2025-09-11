class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        int target = sum / k;

        sort(nums.rbegin(), nums.rend());
        vector<int> buckets(k, 0);

        return backtrack(0, nums, buckets, target);
    }

    bool backtrack(int idx, vector<int>& nums, vector<int>& buckets,
                   int target) {
        if (idx == nums.size()) {
            for (int b : buckets)
                if (b != target)
                    return false;
            return true;
        }

        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i] + nums[idx] > target)
                continue;
            buckets[i] += nums[idx];
            if (backtrack(idx + 1, nums, buckets, target))
                return true;
            buckets[i] -= nums[idx];

            if (buckets[i] == 0)
                break;
        }

        return false;
    }
};

class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;

    void backtrack(vector<int>& nums, vector<int>& path) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            path.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, path);

            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;

        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);
        backtrack(nums, path);

        return res;
    }
};

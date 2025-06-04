class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};

        for (int num : nums) {
            int n = res.size();
            for (int i = 0; i < n; ++i) {
                vector<int> subset = res[i];
                subset.push_back(num);
                if (find(res.begin(), res.end(), subset) == res.end()) {
                    res.push_back(subset);
                }
            }
        }

        return res;
    }
};
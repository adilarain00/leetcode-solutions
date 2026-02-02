class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < 2; ++i) {
            for (int n : nums) {
                ans.push_back(n);
            }
        }

        return ans;
    }
};
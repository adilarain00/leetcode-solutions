class Solution {
private:
    void solve(int idx, int target, vector<int>& arr, vector<int>& list,
               vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(list);
            return;
        }

        for (int i = idx; i < arr.size(); ++i) {
            if (i > idx && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            list.push_back(arr[i]);
            solve(i + 1, target - arr[i], arr, list, result);
            list.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> list;

        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, list, result);

        return result;
    }
};
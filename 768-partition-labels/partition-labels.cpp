class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> last_seen;

        for (int i = 0; i < n; i++) {
            last_seen[s[i]] = i;
        }

        vector<int> ans;
        int i = 0;

        while (i < n) {
            int x = i;
            int j = last_seen[s[i]];

            while (x < j) {
                j = max(j, last_seen[s[x]]);
                x++;
            }

            ans.push_back(j - i + 1);
            i = j + 1;
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (string word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            anagramGroups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }

        return result;
    }
};
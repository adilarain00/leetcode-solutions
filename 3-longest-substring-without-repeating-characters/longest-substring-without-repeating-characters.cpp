class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            while (window.count(s[right])) {
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
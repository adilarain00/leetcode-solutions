class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i = 0, j = 0;

        while (i < word1.size() && j < word2.size()) {
            res += word1[i++];
            res += word2[j++];
        }

        res += word1.substr(i);
        res += word2.substr(j);

        return res;
    }
};
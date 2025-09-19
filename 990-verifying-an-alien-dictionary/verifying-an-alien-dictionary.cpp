class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26, 0);

        for (int i = 0; i < order.size(); i++) {
            rank[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            int len = min(w1.size(), w2.size());
            bool valid = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (rank[w1[j] - 'a'] > rank[w2[j] - 'a'])
                        return false;
                    valid = true;
                    break;
                }
            }

            if (!valid && w1.size() > w2.size())
                return false;
        }
        return true;
    }
};

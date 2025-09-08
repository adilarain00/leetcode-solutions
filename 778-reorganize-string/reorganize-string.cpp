class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto& p : freq)
            pq.push({p.second, p.first});

        string result = "";

        while (pq.size() > 1) {
            auto [count1, ch1] = pq.top();
            pq.pop();
            auto [count2, ch2] = pq.top();
            pq.pop();

            result += ch1;
            result += ch2;

            if (--count1 > 0)
                pq.push({count1, ch1});
            if (--count2 > 0)
                pq.push({count2, ch2});
        }

        if (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            if (count > 1)
                return "";
            result += ch;
        }

        return result;
    }
};

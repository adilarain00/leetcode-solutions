class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.end());

        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();

            if (a != b) {
                int diff = abs(a - b);
                q.push(diff);
            }
        }
        return !q.empty() ? q.top() : 0;
    }
};
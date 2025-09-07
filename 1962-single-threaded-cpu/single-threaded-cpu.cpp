class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int, 3>> indexedTasks;

        for (int i = 0; i < n; i++) {
            indexedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(indexedTasks.begin(), indexedTasks.end());

        vector<int> result;
        long long time = 0;
        int i = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        while (i < n || !pq.empty()) {
            while (i < n && indexedTasks[i][0] <= time) {
                pq.push({indexedTasks[i][1], indexedTasks[i][2]});
                i++;
            }

            if (!pq.empty()) {
                auto [proc, idx] = pq.top();
                pq.pop();
                time += proc;
                result.push_back(idx);
            } else {
                time = indexedTasks[i][0];
            }
        }

        return result;
    }
};

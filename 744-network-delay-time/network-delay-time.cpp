class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        vector<int> dist(n + 1, 1e8);
        dist[k] = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                if (it.second + wt < dist[it.first]) {
                    dist[it.first] = it.second + wt;
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int it = dist[i];
            if (it == 1e8)
                return -1;
            ans = max(ans, it);
        }

        return ans;
    }
};
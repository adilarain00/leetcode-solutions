class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[node] == 1)
            return false;
        if (visited[node] == 2)
            return true;

        visited[node] = 1;
        for (int nei : adj[node]) {
            if (!dfs(nei, adj, visited))
                return false;
        }
        visited[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, adj, visited))
                return false;
        }
        return true;
    }
};

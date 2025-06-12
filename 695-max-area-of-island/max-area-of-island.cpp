class Solution {
public:
    int max = 0;

    void dfs(int i, int j, int m, int n, std::vector<std::vector<int>>& grid,
             int& curr) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        curr++;
        max = std::max(max, curr);

        dfs(i - 1, j, m, n, grid, curr);
        dfs(i + 1, j, m, n, grid, curr);
        dfs(i, j - 1, m, n, grid, curr);
        dfs(i, j + 1, m, n, grid, curr);
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        max = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int curr = 0;
                    dfs(i, j, m, n, grid, curr);
                }
            }
        }
        return max;
    }
};
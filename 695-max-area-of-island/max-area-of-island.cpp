class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        function<int(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0)
                return 0;

            grid[r][c] = 0;

            return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) +
                   dfs(r, c - 1);
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, dfs(r, c));
                }
            }
        }

        return maxArea;
    }
};

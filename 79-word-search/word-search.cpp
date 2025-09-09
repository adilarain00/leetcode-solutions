class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word,
             int position) {
        int n = board.size();
        int m = board[0].size();

        int size = word.size();

        if (size == position)
            return true;

        if (i >= n || i < 0 || j >= m || j < 0 || board[i][j] != word[position])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, i - 1, j, word, position + 1) ||
                     dfs(board, i + 1, j, word, position + 1) ||
                     dfs(board, i, j - 1, word, position + 1) ||
                     dfs(board, i, j + 1, word, position + 1);
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, i, j, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
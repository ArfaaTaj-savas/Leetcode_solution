class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int rows = board.size();
        int cols = board[0].size();

        if (row < 0 || col < 0 || row >= rows || col >= cols)
            return;

        if (board[row][col] != 'O')
            return;

        board[row][col] = '#';

        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;

        int rows = board.size();
        int cols = board[0].size();

        // First and last column
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][cols - 1] == 'O')
                dfs(board, i, cols - 1);
        }

        // First and last row
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[rows - 1][j] == 'O')
                dfs(board, rows - 1, j);
        }

        // Flip surrounded regions
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
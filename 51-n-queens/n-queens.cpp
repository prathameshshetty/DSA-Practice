class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int col, int n) {

        // Found one solution
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Finished checking all columns of this row
        if (col == n)
            return;

        // Place queen if safe
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';

            solve(board, row + 1, 0, n);

            board[row][col] = '.';
        }

        // Try next column
        solve(board, row, col + 1, n);
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(board, 0, 0, n);

        return ans;
    }
};
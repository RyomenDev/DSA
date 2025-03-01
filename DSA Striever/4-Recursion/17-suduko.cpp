// https://leetcode.com/problems/sudoku-solver/

class Solution {
    bool isSafe(int row, int col, vector<vector<char>>& board, char num) {
        int n = board.size();
        // Check row and column
        for (int i = 0; i < n; i++)
            if (board[row][i] == num || board[i][col] == num)
                return false;
        // Check subgrid
        int size = sqrt(n);
        int startRow = (row / size) * size, startCol = (col / size) * size;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[startRow + i][startCol + j] == num)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(row, col, board, num)) {
                            board[row][col] = num;
                            if (solve(board))
                                return true;
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid number found
                }
            }
        }
        return true; // Solution found
    }

public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};

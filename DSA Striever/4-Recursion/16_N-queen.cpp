// https://leetcode.com/problems/n-queens/description/

class Solution {
    vector<vector<string>> ans;
    // bool isSafe(int row,int col,vector<string>& board,int n){
    //     int dubCol=col, dubRow=row;
    //     // <---- left
    //     while(col>=0) if(board[row][col--]=='Q') return false;
    //     // upLeft-diagonal
    //     col=dubCol, row=dubRow;
    //     while(col>=0 && row>=0) if(board[row--][col--]=='Q') return false;
    //     // downLeft-diagonal
    //     col=dubCol, row=dubRow;
    //     while(col>=0 && row<n) if(board[row++][col--]=='Q') return false;
    //     return true;
    // }
    // void solve(int col, vector<string>& board, int n) {
    void solve(int col, vector<string>& board, int n, vector<int> leftRow,
               vector<int> upperDigaonal, vector<int> lowerDiagonal) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            // if(isSafe(row,col,board,n)){
            //     board[row][col]='Q';
            //     solve(col+1,board,n);
            //     board[row][col]='.';
            // }
            if (leftRow[row] == 0 && upperDigaonal[row + col] == 0 &&
                lowerDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDigaonal[row + col] = 1;
                lowerDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, board, n, leftRow, upperDigaonal, lowerDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDigaonal[row + col] = 0;
                lowerDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        vector<int> leftRow(n, 0), upperDigaonal(2 * n, 0),
            lowerDiagonal(2 * n, 0);
        // solve(0, board, n);
        solve(0, board, n, leftRow, upperDigaonal, lowerDiagonal);
        return ans;
    }
};
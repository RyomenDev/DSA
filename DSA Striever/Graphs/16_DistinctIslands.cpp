// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

// Number of Distinct Islands


class Solution {
    set<vector<pair<int, int>>>ans;
    vector<pair<int, int>>temp;
    vector<vector<bool>> vis;
    int I, J;
    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int i, int j, vector<vector<int>>& board) {
        int r = board.size(), c = board[0].size();
        if (i < 0 || i >= r || j < 0 || j >= c || vis[i][j] || board[i][j] == 0)
            return;
        vis[i][j] = true;
        temp.push_back({i - I,j - J});
        for (auto it : dir) {
            int a = it.first, b = it.second;
            dfs(i + a, j + b, board);
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& board) {
        // code here
        int r = board.size(), c = board[0].size();
        vis = vector<vector<bool>>(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (!vis[i][j] && board[i][j] == 1) {
                    I = i, J = j;
                    temp.clear();
                    dfs(i, j, board);
                    ans.insert(temp);
                }
        return ans.size();
    }
};
// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
// https://leetcode.com/problems/flood-fill/description/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#define vvi vector<vector<int>>
class Solution
{
    vvi ans;
    void dfs(int k, int i, int j, int color) // O(n*m)
    {
        int n = ans.size() - 1, m = ans[0].size() - 1;
        // Base case: Out of bounds or current pixel doesn't have the same color
        if (i < 0 || j < 0 || i > n || j > m || ans[i][j] != k)
        {
            return;
        }

        // Update the color of the current pixel
        ans[i][j] = color;

        // Recursive calls for neighboring pixels
        dfs(k, i - 1, j, color); // Up
        dfs(k, i, j - 1, color); // Left
        dfs(k, i, j + 1, color); // Right
        dfs(k, i + 1, j, color); // Down
    }

    void bfs(int k, int i, int j, int color)
    {
        int n = ans.size();
        int m = ans[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        // ans[i][j] = color;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            if (ans[x][y] == k)
                ans[x][y] = color;
            q.pop();
            vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto it : dir)
            {
                int xx = x + it.first;
                int yy = y + it.second;
                if (xx >= 0 && yy >= 0 && xx < n && yy < m && ans[xx][yy] == k)
                {
                    q.push({xx, yy});
                }
            }
        }
        return;
    }

public:
    vvi floodFill(vvi& image, int sr, int sc, int color)
    {
        // Code here
        ans = image;
        int k = image[sr][sc];

        // BASE CONDITION (VERY IMPORTANT OTHERWISE YOU WILL GET RUNTIME ERROR)
        if (k == color)
            return image;
        // dfs(k, sr, sc, color);
        bfs(k, sr, sc, color);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends

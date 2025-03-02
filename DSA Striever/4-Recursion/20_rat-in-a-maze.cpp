// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
    vector<string> ans;
    vector<pair<char, pair<int, int>>> dir{
        // lexicographically smallest orde
      {'D', {1, 0}},  // DOWN 
      {'L', {0, -1}}, // LEFT
      {'R', {0, 1}},  // RIGHT
      {'U', {-1, 0}}  // UP
    };

    bool solve(int i, int j, string& temp, vector<vector<int>>& vis, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (i == n - 1 && j == m - 1) {
            ans.push_back(temp);
            return true;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || !mat[i][j])
            return false;
        vis[i][j] = 1;
        for (auto it : dir) {
            char ch = it.first;
            int x = it.second.first;
            int y = it.second.second;
            temp.push_back(ch);
            solve(i + x, j + y, temp, vis, mat);
            temp.pop_back();
        }
        vis[i][j] = 0;

        return false;
    }
public:
    vector<string> findPath(vector<vector<int>>& mat) {
        // code here
        if (mat[0][0] == 0) return {}; // If start is blocked
        string temp;
        vector<vector<int>>isVisted(mat.size(), vector<int>(mat[0].size(), 0));
        solve(0, 0, temp, isVisted, mat);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            }
            else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            }
            else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
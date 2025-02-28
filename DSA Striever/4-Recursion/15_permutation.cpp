// https://leetcode.com/problems/permutations/submissions/1558321061/

class Solution {
    vector<vector<int>> ans;
    void solve(int i, unordered_map<int, int>& mp, vector<int> temp,
               vector<int>& nums) {
        int n = nums.size();
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (mp.find(j) == mp.end()) {
            // if (mp[j] == 0) {
                temp.push_back(nums[j]);
                mp[j] = 1;
                solve(i + 1, mp, temp, nums);
                temp.pop_back();
                mp.erase(j);
                // mp[j] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        unordered_map<int, int> mp;
        solve(0, mp, temp, nums);
        return ans;
    }
};
// https://www.geeksforgeeks.org/problems/subset-sums2234/1
class Solution
{
    vector<vector<int>> res;
    void func(int ind, vector<int> &temp, vector<int> &nums)
    {
        if (ind == N)
        {
            res.push_back(temp);
            return;
        }
        // pick
        func(ind + 1, temp, nums);
        // not pick
        func(ind + 1, temp, nums);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(0, temp, nums);
        return res;
    }
};
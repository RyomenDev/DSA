// https://leetcode.com/problems/subsets-ii/
// https://www.geeksforgeeks.org/problems/subset-sum-ii/1
class Solution
{
    vector<vector<int>> res;
    void solve(int ind, vector<int> &temp, vector<int> &nums)
    {
        res.push_back(temp);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind and nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            solve(i + 1, temp, nums);
            temp.pop_back();
        }
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
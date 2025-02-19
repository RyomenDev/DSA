// https://leetcode.com/problems/combination-sum/submissions/

class Solution
{
    set<vector<int>> ans;
    void solve(vector<int> nums, vector<int> temp, int index, int tgt)
    {
        if (index >= nums.size())
            return;
        if (tgt == 0)
        {
            ans.insert(temp);
            return;
        }

        if (tgt - nums[index] >= 0)
        {
            temp.push_back(nums[index]);
            solve(nums, temp, index, tgt - nums[index]);
            temp.pop_back();
        }
        else
            return;
        solve(nums, temp, index + 1, tgt);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        solve(arr, {}, 0, target);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};
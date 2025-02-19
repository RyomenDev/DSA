
// https://leetcode.com/problems/combination-sum/submissions/

class Solution
{
    set<vector<int>> ans;
    void solve(vector<int> nums, vector<int> temp, int index, int tgt)
    {
        if (index == nums.size())
        {
            ans.insert(temp);

            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > tgt)
                break;
            temp.push_back(nums[i]);
            solve(nums, temp, i + 1, tgt - nums[i]);

            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        solve(arr, {}, 0, target);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};
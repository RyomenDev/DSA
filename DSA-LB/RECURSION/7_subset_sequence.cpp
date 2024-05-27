//

// https://leetcode.com/problems/subsets/

class Solution
{
public:
    vector<vector<int>> ans;
    void findSubsets(vector<int> &nums, int low, int high)
    {
        if (low == high)
        {
            ans.push_back(nums);
            return;
        }
        findSubsets(nums, low, high);
        findSubsets(nums, low + 1, high);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        findSubsets(nums, 0, nums.size() - 1);
        return ans;
    }
};
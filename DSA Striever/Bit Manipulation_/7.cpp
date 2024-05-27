// https://leetcode.com/problems/single-number-iii/
// two elements appear only once and all the other elements appear exactly twice

#define ll long long
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> ans(2, 0);
        ll xor_all = 0;
        for (int i = 0; i < nums.size(); i++)
            xor_all ^= nums[i];
        int last_set_bit = xor_all & (-xor_all);

        // separate the elements into two groups
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] & last_set_bit) == 0)
                ans[0] ^= nums[i];
            else
                ans[1] ^= nums[i];
        }
        return ans;
    }
};
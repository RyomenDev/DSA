// single number II
// single number which appeared once else thrice
// https://leetcode.com/problems/single-number-ii/submissions/1234055160/


// USING BUCKETS
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (auto x : nums)
            {
                sum += (x >> i) & 1;
            }
            if (sum % 3 != 0)
                ans |= (1 << i);
        }
        return ans;
    }
};


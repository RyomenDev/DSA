
class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // odd / even case
        int median = (n % 2 == 0) ? (nums[n / 2 - 1] + nums[n / 2]) / 2 : nums[n / 2];
        // int median = nums[n / 2];
        if (median == k)
        {
            return 0;
        }
        long long ans = 0;
        if (median > k)
        {
            for (int i = n / 2; i >= 0; i--)
            {
                if (nums[i] <= k)
                    break;
                ans += abs(nums[i] - k);
            }
        }
        else
        {
            for (int i = n / 2; i < n; i++)
            {
                if (nums[i] >= k)
                    break;
                ans += abs(nums[i] - k);
            }
        }
        return ans;
    }
};
// https://www.geeksforgeeks.org/problems/subset-sums2234/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
class Solution
{
    vector<int> ans;
    void solve(int ind, vector<int> &temp, vector<int> &arr, int &sum)
    {
        if (ind == arr.size())
        {
            ans.push_back(sum);
            return;
        }
        temp.push_back(arr[ind]);
        solve(ind + 1, temp, arr, sum + arr[ind]);
        temp.pop_back();
        solve(ind + 1, temp, arr, sum);
    }

public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> temp;
        int sum = 0;
        solve(0, temp, arr, sum);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// SUBSET SUMS

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void solve(int ind, vector<int> &temp, vector<int> &arr)
{
    if (ind == arr.size())
    {
        res.push_back(temp);
        return;
    }
    temp.push_back(arr[ind]);
    solve(ind + 1, temp, arr);
    temp.pop_back();
    solve(ind + 1, temp, arr);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> temp;
    solve(0, temp, arr);
    vector<int> ans;
    for (auto i : res)
    {
        int sum = 0;
        for (auto j : i)
            sum += j;
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
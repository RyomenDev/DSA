
// subsequences : contiguous /non-contiguous, follow order
// subArray : contiguous,order matter

// time complexity : O(2^n*n)
// space complexity : O(n)

// only first condition printed
#include <bits/stdc++.h>
using namespace std;

bool subsequences(int index, vector<int> ans, vector<int> v, int k, int& sum)
{
    int n = v.size();
    if (index >= n)
    {
        // if (accumulate(ans.begin(), ans.end(), 0) == k)
        if (sum == k)
        {
            for (auto x : ans)
                cout << x << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    ans.push_back(v[index]);
    sum += v[index];
    if (subsequences(index + 1, ans, v, k, sum) == true)
        return true;
    ans.pop_back();
    sum -= v[index];
    if (subsequences(index + 1, ans, v, k, sum) == true)
        return true;
    return false;
}

void subsequences1(int index, vector<int> ans, vector<int> v, int k, int& sum)
{
    int n = v.size();
    if (index >= n)
    {
        if (sum == k)
        {
            for (auto x : ans)
                cout << x << " ";
            cout << endl;
        }
        return;
    }
    ans.push_back(v[index]);
    // sum += v[index];
    subsequences1(index + 1, ans, v, k, sum += v[index]);
    ans.pop_back();
    // sum -= v[index];
    subsequences1(index + 1, ans, v, k, sum -= v[index]);
    // return;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 2};
    int k = 5, sum = 0;
    // subsequences(0, {}, v, k, sum);
    subsequences1(0, {}, v, k, sum);
    return 0;
}

// subsequences : contiguous /non-contiguous, follow order
// subArray : contiguous,order matter

// time complexity : O(2^n)
// space complexity : O(n)

// only first condition printed
#include <bits/stdc++.h>
using namespace std;

int subsequences(int index, vector<int> v, int k, int &sum)
{
    int n = v.size();
    if (index >= n)
    {
        if (sum == k)
            return 1;
        return 0;
    }
    sum += v[index];
    int left = subsequences(index + 1, v, k, sum);
    sum -= v[index];
    int right = subsequences(index + 1, v, k, sum);

    return left + right;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 2};
    int k = 5, sum = 0;
    cout << subsequences(0, v, k, sum);
    return 0;
}
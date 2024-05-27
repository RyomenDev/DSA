
// subsequences : contiguous /non-contiguous, follow order
// subArray : contiguous,order matter

// time complexity : O(2^n*n)
// space complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
// print all subsequences
// void subsequences(string s,string ans)
// {
//     if(s.length()==0)
//     {
//         cout<<ans<<" ";
//         return;
//     }
//     char ch=s[0];
//     string ros=s.substr(1);
//     subsequences(ros,ans+ch);
//     subsequences(ros,ans);
// }
void subsequences(int index, vector<int> ans, vector<int> v)
{
    int n = v.size();
    if (index >= n)
    {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
        return;
    }
    ans.push_back(v[index]);
    subsequences(index + 1, ans, v);
    ans.pop_back();
    subsequences(index + 1, ans, v);
}

int main()
{
    // subsequences(0, "abcd", "");
    vector<int> v = {1, 2, 3};
    subsequences(0, {}, v);
    return 0;
}
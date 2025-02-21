
// subsequences1 : contiguous /non-contiguous, follow order
// subArray : contiguous,order matter

// time complexity : O(2^n*n)
// space complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
// print all subsequences
void subsequences(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << " ";
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subsequences(ros, ans + ch);
    subsequences(ros, ans);
}

void subsequences1(int index, vector<int> ans, vector<int> v)
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
    subsequences1(index + 1, ans, v);
    ans.pop_back();
    subsequences1(index + 1, ans, v);
}

// void subsequences2(int index, vector<int> ans, vector<int> v)
// {
//     int n = v.size();
//     if (index >= n)
//     {
//         for (auto x : ans)
//             cout << x << " ";
//         cout << endl;
//         return;
//     }
//     subsequences2(index + 1, ans, v);
//     ans.push_back(v[index]);
//     subsequences2(index + 1, ans, v);
//     ans.pop_back();
// }


void subsequences3(int index, vector<int> ans, vector<int> v)
{
    if (index < 0)
    {
        for (auto x = rbegin(ans); x != rend(ans); x++)
            cout << *x << " ";
        cout << endl;
        return;
    }
    subsequences3(index - 1, ans, v);
    ans.push_back(v[index]);
    subsequences3(index - 1, ans, v);
    ans.pop_back();
}

int main()
{
    subsequences("abcd", "");
    vector<int> v = {1, 2, 3};
    subsequences1(0, {}, v);
    // subsequences2(0, {}, v);
    subsequences3(v.size() - 1, {}, v);
    return 0;
}
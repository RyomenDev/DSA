
// ! Climbing Stairs
// https://leetcode.com/problems /climbing-stairs/description/
// https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1
// https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650  - matrix exponentiation

/*
^ when to use dp
    / count the total ways.
    / figuring out which us giving max or min

    %  when try all possible ways comes up - recursion
*/

/*
& trick
    ^ 1: try to represent the problem in terms of index.
    ^ 2: do all possible stuffs on that and in according to problem.
    ^ 3: if question says count all ways - sumUp all stuffs.
    ^ 4: if question says minimum - take min of stuffs. (similarly max)
*/
/*
& memoization to tabulation
    ^ 1: declare base case
    ^ 2: express various(all) states in for loop
    ^ 3: copy the recurrence and write
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int nthStair(int n)
    {
        //  Code here
        int prev_prev = 0, prev = 1;
        for (int i = 0; i < n; i++)
        {
            int current = 1 + min(prev, prev_prev);
            prev_prev = prev;
            prev = current;
        }
        return prev;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthStair(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
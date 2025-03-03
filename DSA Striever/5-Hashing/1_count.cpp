#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double 
#define endl "\n"

// max hash size - 10^6 for integer inside main
// in global scope - 10^7 

int32_t main()
{
    vector<int>arr{1,2,3,5,2,1,4,6,3,4,8,5,3,2,3,5,6,2,4};
    vector<int>freq(10, 0);
    for (auto i : arr)
    {
        freq[i]++;
    }
    for (int i = 0; i < freq.size(); i++)
    {
        cout << i << " " << freq[i] << endl;
    }
    return 0;
}
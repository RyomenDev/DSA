// https://www.spoj.com/problems/INVCNT/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double 
#define endl "\n"

class SGTree {
public:
    vector<int> seg;
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    // Build the segment tree
    void build(int idx, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = (seg[2 * idx + 1] + seg[2 * idx + 2]);
    }

    // Query the segment tree
    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) // No overlap  // l r low high || low high l r
            return 0;

        if (low >= l && high <= r) // Complete overlap
            return seg[idx];

        // Partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }

    // Update the segment tree
    void update(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] += val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = (seg[2 * idx + 1] + seg[2 * idx + 2]);
    }
};

void Vatsh()
{
    // Your logic goes here
    int n;
    cin >> n;
    vector<int>arr(n + 1, 0);
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    mx += 1;
    vector<int>freq(mx, 0);
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    SGTree sg1(mx);
    sg1.build(0, 0, mx - 1, freq);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]--;
        sg1.update(0, 0, mx - 1, arr[i], -1);
        cnt += sg1.query(0, 0, mx - 1, 1, arr[i] - 1);
    }
    cout << cnt << endl;
}

int32_t main()
{

    int tt = 1;
    //cin >> tt;
    while (tt--)
        Vatsh();

    return 0;
}
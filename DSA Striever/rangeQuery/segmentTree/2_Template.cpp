
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double 
#define endl "\n"

class SGTree {
    vector<int> seg;

public:
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
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    // Query the segment tree
    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) // No overlap  // l r low high || low high l r
            return LLONG_MAX;

        if (low >= l && high <= r) // Complete overlap
            return seg[idx];

        // Partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    // Update the segment tree
    void update(int idx, int low, int high, int i, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

void Vatsh() {
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    SGTree sg1(n1);
    sg1.build(0, 0, n1 - 1, arr1);

    int n2;
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    SGTree sg2(n2);
    sg2.build(0, 0, n2 - 1, arr2);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // Query type
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            int min1 = sg1.query(0, 0, n1 - 1, l1, r1);
            int min2 = sg2.query(0, 0, n2 - 1, l2, r2);
            cout << min(min1, min2) << endl;
        }
        else if (type == 2) { // Update type
            int arrNo, i, val;
            cin >> arrNo >> i >> val;
            if (arrNo == 1)
                sg1.update(0, 0, n1 - 1, i, val);
            else
                sg2.update(0, 0, n2 - 1, i, val);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while (tt--)
        Vatsh();

    return 0;
}

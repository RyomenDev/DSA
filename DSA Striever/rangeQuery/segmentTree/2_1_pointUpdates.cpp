/*
^ given array
^ type 1 -  find min range[1,l,R]
^ type 2 - update idx with given val [2,idx,val]- arr[idx]=val
*/
/*
! query
% segment tree [low, high] query[l,r]
^ partial overlap of node with range // % return (leftNode (*) rightNode)  * operation
^ No overlap with range [L,R] // % return INT_MIN || INT_MAX
    * if(high<l || r<low)
^ complete overlap with (L,R) // % return seq[idx]
    * if(low>=l && high<=r) // % segment tree in b/w
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double 
#define endl "\n"

// Build the segment tree
void segmentTree(int idx, int low, int high, vector<int>& arr, vector<int>& seg) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    segmentTree(2 * idx + 1, low, mid, arr, seg);
    segmentTree(2 * idx + 2, mid + 1, high, arr, seg);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r, vector<int>& seg) {
    // no overlap/
    // l r low high || low high l r
    if (r < low || high < l)
        return INT_MAX;

    // complete overlap
    // l low high r
    if (low >= l && high <= r)
        return seg[idx];

   // Partial overlap
    int mid = (low + high) >> 1;
    int left = query(2 * idx + 1, low, mid, l, r, seg);
    int right = query(2 * idx + 2, mid + 1, high, l, r, seg);
    return min(left, right);
}

// Update the segment tree
void update(int idx, int low, int high, int i, int val, vector<int>& seg) {
    if (low == high) {
        seg[idx] = val;
        return;
    }
    int mid = (low + high) >> 1;
    if (i <= mid)
        update(2 * idx + 1, low, mid, i, val, seg);
    else
        update(2 * idx + 2, mid + 1, high, i, val, seg);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}


void Vatsh1()
{
    // Your logic goes here
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> seg(4 * n, INT_MAX);
    segmentTree(0, 0, n - 1, arr, seg);

    // Printing the segment tree for debugging purposes
    // for (auto i : seg)
    //     cout << i << " ";
    // cout << endl;

     // Number of queries
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r, seg) << endl;
        }
        else {
            int i, val;
            cin >> i >> val;
            update(0, 0, n - 1, i, val, seg);
            arr[i] = val;
        }
    }
}

void Vatsh2() {
    int n1;
    cin >> n1;
    vector<int>arr1(n1);
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    int n2;
    cin >> n2;
    vector<int>arr2(n2);
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
        }
        else if (type == 2) {
            int arrNo, i, val;
            cin >> arrNo >> i >> val;

        }
    }
}

int32_t main()
{
    Vatsh1();
    Vatsh2();

    return 0;
}
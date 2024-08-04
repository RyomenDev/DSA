// https://codeforces.com/contest/339/problem/D
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
    void build(int idx, int low, int high, vector<int>& arr, int orr) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr, !orr);
        build(2 * idx + 2, mid + 1, high, arr, !orr);
        if (orr)
            seg[idx] = (seg[2 * idx + 1] | seg[2 * idx + 2]);
        else
            seg[idx] = (seg[2 * idx + 1] ^ seg[2 * idx + 2]);
    }

    // Update the segment tree
    void update(int idx, int low, int high, int i, int val, int orr) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val, !orr);
        else
            update(2 * idx + 2, mid + 1, high, i, val, !orr);
        if (orr)
            seg[idx] = (seg[2 * idx + 1] | seg[2 * idx + 2]);
        else
            seg[idx] = (seg[2 * idx + 1] ^ seg[2 * idx + 2]);
    }
};

void Vatsh() {
    int n, m;
    cin >> n >> m;
    int size = pow(2, n);
    vector<int> v(size);
    for (int i = 0; i < size; i++)
        cin >> v[i];
    SGTree sg1(size);
    if (n & 1)
        sg1.build(0, 0, size - 1, v, 1);
    else
        sg1.build(0, 0, size - 1, v, 0);
    while (m--) {
        int i, val;
        cin >> i >> val;
        if (n & 1)
            sg1.update(0, 0, size - 1, i - 1, val, 1);
        else
            sg1.update(0, 0, size - 1, i - 1, val, 0);
        cout << sg1.seg[0] << endl;
    }
}

int32_t main() {
    int tt = 1;
    while (tt--)
        Vatsh();
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 
// #define ld long double 
// #define endl "\n"

// int solve(int a, int b, vector<int>& v) {
//     v[a] = b;
//     bool flag = 1;
//     queue<int>q;
//     for (int i = 0; i < v.size(); i++)
//         q.push(v[i]);
//     while (q.size() > 1) {
//         int size = q.size();
//         for (int i = 0; i < size; i += 2) {
//             int num1 = q.front();
//             q.pop();
//             int num2 = q.front();
//             q.pop();
//             int temp = (flag) ? (num1 | num2) : (num1 ^ num2);
//             q.push(temp);
//         }
//         flag = !flag;
//     }
//     return q.front();
// }

// void Vatsh()
// {
//     int n, m;
//     cin >> n >> m;
//     int size = pow(2, n);
//     vector<int>v(size);
//     for (int i = 0; i < size; i++)
//         cin >> v[i];
//     while (m--) {
//         int a, b;
//         cin >> a >> b;
//         cout << solve(a - 1, b, v) << endl;
//     }
// }

// int32_t main()
// {

//     int tt = 1;
//     //cin >> tt;
//     while (tt--)
//         Vatsh();

//     return 0;
// }
// https://codeforces.com/contest/380/problem/C

/*
! merge
^ full = left.full + right.full + min(left.open, right.close)
^ open = left.open + right.open - min(left.open, right.close)
^ close = left.close + right.close - min(left.open, right.close)
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long    
#define ld long double 
#define endl "\n"

class SGTree {
public:
    struct Info {
        int open, close, full;
        Info(int _open = 0, int _close = 0, int _full = 0) {
            open = _open;
            close = _close;
            full = _full;
        }
    };

    vector<Info> seg;

    SGTree(int n) {
        seg.resize(4 * n + 1);
    }

    Info merge(Info left, Info right) {
        Info ans;
        int matched = min(left.open, right.close);
        ans.full = left.full + right.full + matched;
        ans.open = left.open + right.open - matched;
        ans.close = left.close + right.close - matched;
        return ans;
    }

    void build(int idx, int low, int high, const string& s) {
        if (low == high) {
            seg[idx] = Info(s[low] == '(', s[low] == ')', 0);
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, s);
        build(2 * idx + 2, mid + 1, high, s);
        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    Info query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) {
            return Info();
        }
        if (low >= l && high <= r) {
            return seg[idx];
        }
        int mid = (low + high) / 2;
        Info left = query(2 * idx + 1, low, mid, l, r);
        Info right = query(2 * idx + 2, mid + 1, high, l, r);
        return merge(left, right);
    }
};

void Vatsh() {
    string s;
    cin >> s;
    int n = s.size();
    int size = pow(2, n);
    SGTree sg1(size + 1);
    sg1.build(0, 0, n - 1, s);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        SGTree::Info ans = sg1.query(0, 0, n - 1, l - 1, r - 1);
        cout << ans.full * 2 << endl;
    }
}

int32_t main() {
    int tt = 1;
    while (tt--)
        Vatsh();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int l, r;
    ll sum, lazy;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        lazy = sum = 0;
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int rl, int rr, ll val) {
        if(rr < l || r < rl)
            return;
        if(rl <= l && r <= rr) {
            lazy += val;
            return;
        }
        sum += val * (ll)(min(r, rr) - max(l, rl) + 1);
        left->upd(rl, rr, val);
        right->upd(rl, rr, val);
    }

    ll qry(int rl, int rr) {
        if(rr < l || r < rl)
            return 0;
        if(rl <= l && r <= rr)
            return sum + (ll)(r - l + 1) * lazy;
        sum += (ll)(r - l + 1) * lazy;
        left->lazy += lazy;
        right->lazy += lazy;
        lazy = 0;
        return left->qry(rl, rr) + right->qry(rl, rr);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        node tree = node(1, n);
        while(c--) {
            int t, p, q;
            cin >> t >> p >> q;
            if(t == 0) {
                ll v;
                cin >> v;
                tree.upd(p, q, v);
            }
            else
                cout << tree.qry(p, q) << endl;
        }
    }
}
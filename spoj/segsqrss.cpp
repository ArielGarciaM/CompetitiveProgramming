#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll EMPTY = 1e14 + 53523;

struct node {
    ll l, r, sum, sumsq, lazys, lazyc;
    node *left, *right;

    node(ll l, ll r, ll *A) : l(l), r(r) {
        lazyc = EMPTY;
        lazys = 0;
        if(l == r) {
            sum = A[l];
            sumsq = sum*sum;
        }
        else {
            ll m = (l + r)/2;
            left = new node(l, m, A);
            right = new node(m + 1, r, A);
            merge();
        }
    }

    void merge() {
        sum = left->getsum() + right->getsum();
        sumsq = left->getsq() + right->getsq();
    }

    ll getsum() {
        ll res = sum;
        if(lazyc != EMPTY)
            res = lazyc * (r - l + 1ll);
        res += lazys * (r - l + 1ll);
        return res;
    }

    ll getsq() {
        ll res = sumsq, s = sum;
        if(lazyc != EMPTY) {
            res = lazyc * lazyc * (r - l + 1ll);
            s = lazyc * (r - l + 1ll);
        }
        res += lazys*(2ll*s + (r - l + 1ll)*lazys);
        return res;
    }

    void compose(ll c, ll s) {
        if(c != EMPTY) {
            lazyc = c;
            lazys = 0;
        }
        lazys += s;
    }

    void push() {
        left->compose(lazyc, lazys);
        right->compose(lazyc, lazys);
        lazyc = EMPTY, lazys = 0;
    }

    void change(int rl, int rr, ll val) {
        if(r < rl || rr < l)
            return;
        if(rl <= l && r <= rr) {
            compose(val, 0);
            return;
        }
        push();
        left->change(rl, rr, val);
        right->change(rl, rr, val);
        merge();
    }

    void add(int rl, int rr, ll val) {
        if(r < rl || rr < l)
            return;
        if(rl <= l && r <= rr) {
            compose(EMPTY, val);
            return;
        }
        push();
        left->add(rl, rr, val);
        right->add(rl, rr, val);
        merge();
    }

    ll qry(int rl, int rr) {
        if(r < rl || rr < l)
            return 0;
        if(rl <= l && r <= rr)
            return getsq();
        push();
        merge();
        return left->qry(rl, rr) + right->qry(rl, rr);
    }
};

const int MAXN = 1e5 + 5;
ll A[MAXN];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ":\n";
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; i++)
            cin >> A[i];
        node tree = node(1, n, A);
        while(q--) {
            int t, l, r;
            cin >> t >> l >> r;
            if(t == 2) {
                cout << tree.qry(l, r) << endl;
                continue;
            }
            ll v;
            cin >> v;
            if(t == 0)
                tree.change(l, r, v);
            if(t == 1)
                tree.add(l, r, v);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e9 + 2;

struct node {
    int l, r, mx;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        mx = -INF;
        if(l != r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int pos, int val) {
        if(pos < l || r < pos)
            return;
        if(l == r) {
            mx = val;
            return;
        }
        left->upd(pos, val);
        right->upd(pos, val);
        mx = max(left->mx, right->mx);
    }

    int qry(int rl, int rr) {
        if(r < rl || rr < l)
            return -INF;
        if(rl <= l && r <= rr)
            return mx;
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int v[20][MAXN], dp[MAXN], L, R;

int rmq(int l, int r) {
    int len = r - l + 1, b = 31 - __builtin_clz(len);
    return max(v[b][l], v[b][r - (1 << b) + 1]);
}

bool check(int m, int v, node &tree) {
    int lo = m - R, hi = m - L;
    if(rmq(lo + 1, m) < v)
        return false;
    while(lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if(rmq(mi + 1, m) >= v)
            lo = mi;
        else
            hi = mi - 1;
    }
    if(tree.qry(m - R, lo) >= v)
        return true;
    return false;
}

int calc(int m, node &tree) {
    if(m < L)
        return -INF;
    if(L <= m && m <= R)
        return rmq(1, m);
    if(tree.qry(m - R, m - L) < 0)
        return -INF;
    int lo = -INF, hi = INF;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(check(m, mi, tree))
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo;
}

int main() {
    int n;
    cin >> n >> L >> R;
    node tree = node(1, n);
    for(int i = 1; i <= n; i++)
        cin >> v[0][i];
    for(int l = 1; l < 20; l++) {
        for(int i = 1; i + (1 << l) - 1 <= n; i++)
            v[l][i] = max(v[l - 1][i], v[l - 1][i + (1 << (l - 1))]);
    }
    dp[0] = INF;
    for(int i = 1; i <= n; i++) {
        dp[i] = calc(i, tree);
        tree.upd(i, dp[i]);
    }
    cout << dp[n] << endl;
}
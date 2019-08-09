#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;

struct node {
    int l, r;
    node *left, *right;
    ll val;

    node(int l, int r) : l(l), r(r), val(0) {
        if(l != r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int p, ll v) {
        if(p < l || r < p) return;
        if(l == r) {
            val = max(v, val);
            return;
        }
        left->upd(p, v);
        right->upd(p, v);
        val = max(left->val, right->val);
    }

    ll qry(int rl, int rr) {
        if(rr < l || r < rl) return -INF;
        if(rl <= l && r <= rr) return val;
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

struct cmp {
    bool operator() (ii a, ii b) const {
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

map<ii, ll, cmp> xd;
map<int, int> pm, vm;
int p[MAXN], v[MAXN];
ll c[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int b, f;
        ll d;
        cin >> b >> f >> d;
        xd[{b, f}] += d;
        p[i] = b;
        v[i] = f;
    }
    sort(p, p + n);
    int pt = 1;
    for(int i = 0; i < n; i++) {
        if(i > 0 && p[i] != p[i - 1])
            pt++;
        pm[p[i]] = pt;
    }
    sort(v, v + n);
    pt = 1;
    for(int i = 0; i < n; i++) {
        if(i > 0 && v[i] != v[i - 1])
            pt++;
        vm[v[i]] = pt;
    }
    pt = 1;
    for(auto x : xd) {
        p[pt] = pm[x.first.first];
        v[pt] = vm[x.first.second];
        c[pt] = x.second;
        pt++;
    }
    node tree(0, n);
    for(int i = 1; i <= pt; i++) {
        ll x = tree.qry(0, v[i] - 1);
        tree.upd(v[i], x + c[i]);
    }
    cout << tree.qry(1, n) << endl;
}
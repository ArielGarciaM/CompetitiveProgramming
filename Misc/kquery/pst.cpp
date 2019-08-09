#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r, sum;
    node *left, *right;

    node(int l, int r, int sum = 0) : l(l), r(r), sum(sum) {}

    void merge() { sum = left->sum + right->sum; }

    void build() {
        if(l == r)
            return;
        else {
            int mi = (l + r)/2;
            left = new node(l, mi);
            right = new node(mi + 1, r);
            left->build();
            right->build();
            merge();
        }
    }

    node* upd(int p, int v) {
        if(r < p || p < l) return this;
        if(l == r) return new node(l, r, sum + v);
        node* res = new node(l, r);
        res->left = left->upd(p, v);
        res->right = right->upd(p, v);
        res->merge();
        return res;
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl) return 0;
        if(rl <= l && r <= rr) return sum;
        return left->qry(rl, rr) + right->qry(rl, rr);
    }
};

const int MAXN = 3e5 + 5;
int a[MAXN], sa[MAXN];
map<int, int> to;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, lans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], sa[i] = a[i];
    sort(sa, sa + n);
    for(int i = 0; i < n; i++) to[sa[i]] = i + 1;
    for(int i = 0; i < n; i++) a[i] = to[a[i]];
    //for(int i = 0; i < n; i++) cout << a[i] << " ";
    //cout << endl;
    vector<node*> trees(n + 1);
    trees[0] = new node(1, n);
    trees[0]->build();
    for(int i = 1; i <= n; i++)
        trees[i] = trees[i - 1]->upd(a[i - 1], 1);
    int q;
    cin >> q;
    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l ^= lans;
        r ^= lans;
        k ^= lans;
        if(l < 1) l = 1;
        if(r > n) r = n;
        if(l > r) {
            lans = 0;
            cout << lans << '\n';
            continue;
        }
        if(k < sa[0]) {
            cout << r - l + 1 << '\n';
            lans = r - l + 1;
            continue;
        }
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(sa[mi] <= k) lo = mi;
            else hi = mi - 1;
        }
        k = lo + 1;
        lans = r - l + 1 - (trees[r]->qry(1, k) - trees[l - 1]->qry(1, k));
        cout << lans << '\n';
    }
}
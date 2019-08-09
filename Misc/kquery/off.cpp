#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e4 + 5;
int BIT[MAXN];
typedef pair<int, int> ii;

struct query {
    int l, r, k, id;
    bool operator< (const query& o) const { return k < o.k; }
};

void upd(int p, int v) {
    for(; p < MAXN; p += (p & -p)) BIT[p] += v; 
}
int sum(int p) {
    int s = 0;
    for(; p > 0; p -= (p & -p)) s += BIT[p];
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) upd(i, 1);
    vector<ii> v;
    vector<query> qry;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    cin >> q;
    vector<int> ans(q);
    for(int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        qry.push_back({l, r, k, i});
    }
    sort(qry.begin(), qry.end());
    int ptr = 0;
    for(int i = 0; i < q; i++) {
        int k = qry[i].k, l = qry[i].l, r = qry[i].r;
        while(ptr < n && v[ptr].first <= k)
            upd(v[ptr].second, -1), ptr++;
        ans[qry[i].id] = sum(r) - sum(l - 1);
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

struct node {
    int l, r;
    ll mx, lazy;
    node *left, *right;

    inline ll getmx() { return mx + lazy; }
    inline void merge() { mx = max(left->getmx(), right->getmx()); }
    inline void compose(ll u) { lazy += u; }
    inline void push() {
        left->compose(lazy);
        right->compose(lazy);
        lazy = 0;
        merge();
    }

    node() {}
    node(int l, int r, ll *A) : l(l), r(r), lazy(0), mx(0) {
        if(l == r)
            mx = A[l];
        else {
            int mi = (l + r)/2;
            left = new node(l, mi, A);
            right = new node(mi + 1, r, A);
            merge();
        }
    }

    void upd(int rl, int rr, ll v) {
        if(rr < l || r < rl) return;
        if(rl <= l && r <= rr) { 
            compose(v);
            return;
        }
        push();
        left->upd(rl, rr, v);
        right->upd(rl, rr, v);
        merge();
    }

    ll qry(int rl, int rr) {
        if(rr < l || r < rl) return -INF;
        if(rl <= l && r <= rr) return getmx();
        push();
        merge();
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

struct query {
    int r, c, t;
    ll u;
    bool operator< (const query &o) const { return t < o.t; }
};

vector<query> qs;
node trees[255];
ll S[255][255], A[255][255];
int n, m, k;
ll lim;

void update(int r, int c, ll u) {
    //cout << "updated [" << max(r - k + 1, 1) << ", " << min(n - k + 1, r) << "] x [" << max(c - k + 1, 1) << ", " << min(m - k + 1, c) << "] with " << u << '\n';
    for(int R = max(r - k + 1, 1); R <= min(n - k + 1, r); R++) {
        trees[R].upd(max(c - k + 1, 1), min(m - k + 1, c), u);
    }
}

bool has() {
    for(int i = 1; i <= n - k + 1; i++)
        if(trees[i].qry(1, m - k + 1) > lim) return true;
    return false;
}

int main() {
    cin >> n >> m >> k >> lim;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ll p;
            cin >> p;
            S[i][j] = p + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n - k + 1; i++) {
        for(int j = 1; j <= m - k + 1; j++) {
            A[i][j] = S[i + k - 1][j + k - 1] - S[i + k - 1][j - 1] - S[i - 1][j + k - 1] + S[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n - k + 1; i++) {
        //cout << "GOT" << i << endl;
        trees[i] = node(1, m - k + 1, A[i]);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int r, c, t;
        ll u;
        cin >> r >> c >> u >> t;
        qs.push_back({r, c, t, u});
    }
    int prevt = 0;
    sort(qs.begin(), qs.end());
    for(auto q : qs) {
        if(q.t != prevt) {
            if(has()) {
                cout << prevt << '\n';
                return 0;
            }
            prevt = q.t;
        }
        update(q.r, q.c, q.u);
    }
    if(has())
        cout << prevt << '\n';
    else
        cout << "-1\n";
    return 0;
}
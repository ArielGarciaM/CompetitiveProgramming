#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
ll maxlis[MAXN], wt[MAXN];
int pos[MAXN];

struct node {
    int l, r;
    ll mx;
    node *left, *right;

    node(int l, int r) : l(l), r(r) {
        mx = -INF;
        if(l != r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int pos, ll val) {
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

    ll qrymx(int rl, int rr) {
        if(rr < l || r < rl)
            return -INF;
        if(rl <= l && r <= rr)
            return mx;
        return max(left->qrymx(rl, rr), right->qrymx(rl, rr));
    }
};

int main() {
    int n;
    cin >> n;
    node st = node(1, n);
    for(int i = 1; i <= n; i++)
        cin >> pos[i];
    for(int i = 1; i <= n; i++)
        cin >> wt[i];
    for(int i = 1; i <= n; i++) {
        int p = pos[i];
        ll mx = st.qrymx(1, p);
        maxlis[p] = wt[i] + max(mx, 0ll);
        st.upd(p, maxlis[p]);
    }
    ll mx = 0;
    for(int i = 1; i <= n; i++)
        mx = max(mx, maxlis[i]);
    cout << mx << endl;
}
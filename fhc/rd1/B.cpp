#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll inv = (MOD + 1)/2;

struct node {
    int l, r, val;
    node *left, *right;

    node(int _l, int _r) : l(_l), r(_r), val(0) {
        if(l != r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
            val = min(left->val, right->val);
        }
    }

    void upd(int p, int v) {
        if(r < p || p < l) return;
        if(l == r) { val = v; return; }
        left->upd(p, v), right->upd(p, v);
        val = min(left->val, right->val);
    }

    int qry(int ll, int rr) {
        if(rr < l || r < ll || l > r) return INF;
        if(ll <= l && r <= rr) return val;
        return min(left->qry(ll, rr), right->qry(ll, rr));
    }
};

int solve() {
    ll ans = 0, p2 = 1;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> pf(n + 1);
    for(int i = 1; i <= n; i++) {
        pf[i] = pf[i - 1] + (s[i - 1] == 'A' ? -1 : 1);
        p2 <<= 1;
        if(p2 >= MOD) p2 -= MOD;
    }
    node t(0, n);
    int sf = 0, rem = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(pf[n] - pf[i] - 2*rem - t.qry(i + 1, n) > k) {
            rem++;
            s[i] = 'A';
            ans += p2;
            if(ans >= MOD)
                ans -= MOD;
        }
        sf = sf + (s[i] == 'A' ? -1 : 1);
        t.upd(i, sf);
        p2 = (p2 * inv)%MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": " << solve() << '\n'; 
    }
}
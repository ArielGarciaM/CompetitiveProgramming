#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int MAXN = 5e5 + 5;
const int INF = 1e18;
ll deg[MAXN];
ll pref[MAXN], delta[MAXN], ndelta[MAXN], diff[MAXN], n, lv = 0;

struct node {
    int l, r, mn, mx;
    node *left, *right;

    node(int l, int r, ll *A) : l(l), r(r) {
        if(l == r)
            mn = mx = A[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, A);
            right = new node(m + 1, r, A);
            mn = min(left->mn, right->mn);
            mx = max(left->mx, right->mx);
        }
    }

    ll query(int rl, int rr) {
        if(r < rl || rr < l)
            return INF;
        if(rl <= l && r <= rr)
            return mn;
        return min(left->query(rl, rr), right->query(rl, rr));
    }

    ll querymx(int rl, int rr) {
        if(r < rl || rr < l)
            return -INF;
        if(rl <= l && r <= rr)
            return mx;
        return max(left->querymx(rl, rr), right->querymx(rl, rr));
    }
};

ll bs(ll bnd, int l) {
    int lo = l, hi = n;
    if(deg[n] > bnd || lo > hi)
        return -1;
    while(lo != hi) {
        int mi = (lo + hi)/2;
        if(deg[lo] > bnd)
            lo = mi + 1;
        else
            hi = mi;
    }
    return lo;
}

signed main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> deg[i];
        if(deg[i] == 0)
            lv++;
    }
    sort(deg, deg + n, [&](ll a, ll b){return a > b;});
    for(int i = n; i >= 1; i--) {
        deg[i] = deg[i - 1];
    }
    ll sdeg = 0;
    for(int i = 1; i <= n; i++) {
        //cout << deg[i] << " ";
        sdeg += deg[i];
        pref[i] = sdeg;
    }
    //cout << endl;
    ll tot = pref[n];
    for(ll k = 1; k <= n; k++) {
        ll m = bs(k, k + 1ll);
        //cout << k << " " << m << endl;
        ll del = pref[k];
        if(m == -1) {
            del -= k*(n - 1ll);
            delta[k] = del;
        }
        else {
            del -= k*(k - 1ll);
            del -= (tot - pref[m - 1ll]);
            del -= k*(m - k - 1ll);
            delta[k] = del;
        }
        diff[k] = delta[k] - k;
    }
    for(ll i = 1; i <= n; i++) {
        if(i < n) {
            ndelta[i] = deg[i + 1] + min(deg[i + 1], i + 1) - delta[i + 1];
        }
        else
            ndelta[i] = n*(n + 1ll) - tot;
    }
    /*for(int i = 1; i <= n; i++)
        cout << delta[i] << " " << ndelta[i] << endl;*/
    node dtree = node(1, n, delta);
    node ndtree = node(1, n, ndelta);
    node difftree = node(1, n, diff);
    bool alo = false;
    for(int m = n; m >= 0; m--) {
        // Check if guy can be d_{p + 1/2} idk i guess
        // Deg must lie in range [lbnd, hbnd]
        if(difftree.querymx(1, m) > 0)
            continue;
        ll lbnd = 0, hbnd = n - lv;
        if(m < n)
            lbnd = deg[m + 1];
        if(m > 0)
            hbnd = deg[m] - 1;
        if(lbnd > hbnd)
            continue;
        if(m == 0) {
            hbnd = min(hbnd, deg[1] + min(deg[1], 1ll) - delta[1]);
        }
        hbnd = min(hbnd, ndtree.query(m, n));
        if(m > 0) {
            lbnd = max(lbnd, dtree.querymx(1, m));
        }
        if(lbnd <= hbnd) {
            for(int j = lbnd; j <= hbnd; j++) {
                if(j % 2 == tot % 2) {
                    alo = true;
                    cout << j << " ";
                }
            }
        }
    }
    if(!alo) {
        cout << -1 << endl;
        return 0;
    }
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool Q;
struct Line {
    mutable ll k, m , p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};

struct LineContainer : multiset<Line> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf;
            return false;
        }
        if(x->k == y->k)
            x->p = x->m > y->m ? inf : -inf;
        else
            x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }

    void add(ll k, ll m){
        auto z = insert({k, m, 0}), y = z++, x = y;
        while(isect(y, z))
            z = erase(z);
        if(x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    ll query(ll x) {
        assert(!empty());
        Q = 1; auto l = *lower_bound({0, 0, x}); Q = 0;
        return l.k*x + l.m;
    }
};

const int MAXN = 2e5 + 5;
ll dp[MAXN], h[MAXN];

int main() {
    LineContainer cht;
    int n;
    ll c;
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    dp[1] = 0;
    cht.add(2ll*h[1], -h[1]*h[1]);
    for(int m = 2; m <= n; m++) {
        dp[m] = h[m]*h[m] + c - cht.query(h[m]);
        cht.add(2ll*h[m], -h[m]*h[m] - dp[m]);
    }
    cout << dp[n] << endl;
}
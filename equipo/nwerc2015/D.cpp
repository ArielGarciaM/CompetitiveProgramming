#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
ll dp[MAXN], n, r, p;

ll f(ll m, ll k) {
    return (k - 1) * p + dp[(m + k - 1)/k];
}

ll bs(ll m) {
    if(m == 2)
        return 2;
    ll lo = 2, hi = m - 1;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(f(m, mi) <= f(m, mi + 1))
            hi = mi;
        else
            lo = mi + 1;
    }
    return lo;
}

int main() {
    cin >> n >> r >> p;
    dp[1] = 0;
    for(int m = 2; m <= n; m++) {
        dp[m] = r + min(f(m, m), f(m, bs(m)));
    }
    cout << dp[n] << endl;
}
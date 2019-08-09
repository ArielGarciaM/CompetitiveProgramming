#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 2e18;

ll solve(ll n, ll k, ll b) {
    if(k > b || (((1ll << k) - 1)<<(b - k + 1ll)) <= n) return INF;
    if(k == 0) return 0;
    if((1ll << k) - 1 > n) return (1ll << k) - 1ll;
    ll mn = INF;
    ll msb = 63 - __builtin_clzll(n);
    mn = min(mn, (1ll << (msb + 1ll)) + solve(-1, k - 1, msb));
    mn = min(mn, (1ll << msb) + solve(n - (1ll << msb), k - 1, msb - 1));
    return mn;
}

int main() {
    ll n, k;
    cin >> n >> k;
    cout << solve(n, k, 62) << endl;
}
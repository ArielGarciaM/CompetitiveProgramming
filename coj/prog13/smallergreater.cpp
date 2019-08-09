#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ll m, k;
    while(cin >> m >> k) {
        ll mn = LLONG_MAX;
        ll t = (1ll << k) - 1;
        bool done = false;
        for(ll d = 0; d + k <= 60; d++) {
            if((m & (t << d)) == (t << d)) {
                cout << m << '\n';
                done = true;
                break;
            }
        }
        if(done)
            continue;
        ll ans = LLONG_MAX;
        for(ll d = 0; d + k <= 60; d++) {
            ll cand = (m | (t << d));
            cand >>= d;
            cand <<= d;
            ans = min(ans, cand);
        }
        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2020];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n) {
        vector<ll> v(n);
        for(auto &x : v) cin >> x;
        ll ans = 0;
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                dp[r] = v[r];
                if(r - l)
                    dp[r] = max(dp[r], dp[r - 1] + v[r]);
            }
            ll mx = LLONG_MIN;
            for(int r = l; r < n; r++) {
                mx = max(mx, dp[r]);
                ans ^= mx;
            }
        }
        cout << ans << '\n';
    }
}
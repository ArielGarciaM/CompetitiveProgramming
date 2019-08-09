#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll mpow(ll b, ll e) {
    if(e == 0)
        return 1;
    b %= MOD;
    if(e % 2)
        return (b * mpow(b, e - 1))%MOD;
    ll p = mpow(b, e/2);
    return (p * p)%MOD;
}

ll inv(ll b) {
    return mpow(b, MOD - 2);
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n, k;
        cin >> n >> k;
        vector<ll> x(n), y(n), a(n), suff(n);
        ll c, d, e1, e2, f;
        cin >> x[0] >> y[0] >> c >> d >> e1 >> e2 >> f;
        for(int i = 1; i < n; i++) {
            x[i] = (c*x[i - 1] + d*y[i - 1] + e1)%f;
            y[i] = (d*x[i - 1] + c*y[i - 1] + e2)%f;
        }
        for(int i = 0; i < n; i++)
            a[i] = (x[i] + y[i])%f;
        suff[n - 1] = a[n - 1];
        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        for(int i = n - 2; i >= 0; i--)
            suff[i] = suff[i + 1] + a[i];
        ll ans = 0;
        for(ll x = n - 1; x >= 1; x--) {
            ll s = suff[x];
            ll y = (x + 1);
            ll aux = mpow(y, k + 1) - 1;
            aux = (aux * inv(x))%MOD;
            aux--;
            ans = (ans + aux*s)%MOD;
        }
        cout << ans << endl;
        ans = (ans + k*suff[0])%MOD;
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}
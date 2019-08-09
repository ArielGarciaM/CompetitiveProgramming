#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
ll p10[30];

int main() {
    p10[0] = 1;
    for(int i = 1; i < 30; i++)
        p10[i] = (p10[i - 1] * 10) % MOD;

    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    ll cur = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        ll x = v[i];
        int dig = 1;
        while(x > 0) {
            ll d = x % 10;
            ans = (ans + d * p10[2*dig - 1] * n)%MOD;
            x /= 10;
            dig++;
        }
    }
    cout << ans << endl;
}
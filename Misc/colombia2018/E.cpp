#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> sq;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= n - i; j++) {
            sq.emplace_back(i, j);
        }
    }
    for(int i = 0; i < sq.size(); i++) {
        for(int j = i + 1; j < sq.size(); j++) {
            ll a = abs(sq[i].first - sq[j].first), b = abs(sq[i].second - sq[j].second);
            if(__gcd(a, b) > 1)
                ans++;
        }
    }
    cout << ans << endl;
}
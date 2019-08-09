#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> pref(1);
    for(int i = 0; i < n; i++) {
        ll y;
        cin >> y;
        ll x = (pref.back() + y) % n;
        if(x < 0)
            x += n;
        pref.push_back(x);
    }
    ll ans = 0;
    map<ll, ll> cnt;
    for(int i = 0; i <= n; i++) {
        ans += cnt[pref[i]];
        cnt[pref[i]]++;
    }
    cout << ans << '\n';
}
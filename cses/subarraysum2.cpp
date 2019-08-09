#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> pref(1);
    for(int i = 0; i < n; i++) {
        ll y;
        cin >> y;
        pref.push_back(pref.back() + y);
    }
    ll ans = 0;
    map<ll, ll> cnt;
    for(int i = 0; i <= n; i++) {
        ans += cnt[pref[i] - x];
        cnt[pref[i]]++;
    }
    cout << ans << '\n';
}
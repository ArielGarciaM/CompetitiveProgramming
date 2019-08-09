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
    int l = 0, r = 0;
    ll ans = 0;
    while(r <= n) {
        if(l < r && pref[r] - pref[l] > x) {
            l++;
            continue;
        }
        if(pref[r] - pref[l] == x) {
            l++;
            ans++;
            continue;
        }
        r++;
    }
    cout << ans << '\n';
}
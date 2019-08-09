#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll ans = -1e18, cur = 0;
    int n;
    cin >> n;
    while(n--) {
        ll x;
        cin >> x;
        cur = max(x, x + cur);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
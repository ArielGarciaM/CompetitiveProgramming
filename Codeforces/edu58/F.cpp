#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[400][400][401], a[400];

int minimize(int l, int r, int k) {
    if(l == r)
        return 0;
    if(k == 0)
        return a[r] - a[l];
    int lo = l, hi = r;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(a[mi] - a[l] <= dp[mi][r][k - 1])
            lo = mi;
        else
            hi = mi - 1;
    }
    int x = max(a[lo] - a[l], dp[lo][r][k - 1]);
    if(lo < r)
        x = min(x, max(a[lo + 1] - a[l], dp[lo + 1][r][k - 1]));
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int len = 0; len < n; len++) {
        for(int st = 0; st + len < n; st++) {
            for(int k = 0; k <= n; k++) {
                dp[st][st + len][k] = minimize(st, st + len, k);
            }
        }
    }
    ll ans = 0;
    while(m--) {
        ll s, f, c, r;
        cin >> s >> f >> c >> r;
        ans = max(ans, (ll)dp[s - 1][f - 1][r] * c);
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 405;
ll memo[MAXN][MAXN], a[MAXN], pref[MAXN];

ll dp(int l, int r) {
    if(l == r)
        return 0;
    if(memo[l][r] != -1)
        return memo[l][r];
    ll mn = LLONG_MAX;
    for(int i = l; i < r; i++)
        mn = min(mn, dp(l, i) + dp(i + 1, r));
    return memo[l][r] = mn + (pref[r] - pref[l - 1]);
}

int main() {
    int n;
    cin >> n;
    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    memset(memo, -1, sizeof memo);
    cout << dp(1, n) << endl;
}
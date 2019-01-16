#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 4e18;
const int MAXN = 1e6 + 5;
ll memo[MAXN], n, r, p;

ll dp(ll m) {
    if(m == 1)
        return 0;
    if(memo[m] != -1)
        return memo[m];
    ll mn = INF;
    for(ll k = 2; k <= m; k++)
        mn = min(mn, r + (k - 1ll)*p + dp((m + k - 1)/k));
    return memo[m] = mn;
}

int main() {
    cin >> n >> r >> p;
    memset(memo, -1, sizeof memo);
    cout << dp(n) << endl;
}
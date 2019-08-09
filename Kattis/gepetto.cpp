#include <bits/stdc++.h>
using namespace std;

int n, m, memo[1 << 20];
bool mat[20][20];

int dp(int msk) {
    if(memo[msk] != -1)
        return memo[msk];
    if(msk == 0)
        return 1;
    int f = __builtin_ctz(msk);
    int nmsk = 0;
    for(int i = f + 1; i < n; i++) {
        if(!mat[f][i] && (msk & (1 << i)))
            nmsk |= (1 << i);
    }
    int ans = dp(msk^(1 << f)) + dp(nmsk);
    return memo[msk] = ans;
}

int main() {
    cin >> n;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mat[a][b] = true;
        mat[b][a] = true;
    }
    memset(memo, -1, sizeof memo);
    cout << dp((1 << n) - 1) << endl;
}
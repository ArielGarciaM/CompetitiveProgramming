#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e4 + 10;
ll dp[MAXN], ans[MAXN];
const ll MOD = 1e9 + 7;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    dp[0] = 1;
    for(int m = 1; m < MAXN; m++) {
        for(int i = m; i < MAXN; i++) {
            dp[i] += dp[i - m];
            if(dp[i] > MOD)
                dp[i] -= MOD;
        }
    }
    int n;
    while(cin >> n)
        cout << dp[n] << '\n';
}

// 5
// 4 + 1
// 3 + 2
// 3 + 1 + 1
// 2 + 2 + 1
// 2 + 1 + 1 + 1
// 1 + 1 + 1 + 1 + 1

// 6
// 5 + 1
// 4 + 2
// 3 + 3
// 4 + 1 + 1
// 3 + 2 + 1
// 2 + 2 + 2
// 3 + 1 + 1 + 1
// 2 + 2 + 1 + 1
// 2 + 1 + 1 + 1 + 1
// 1 + 1 + 1 + 1 + 1 + 1
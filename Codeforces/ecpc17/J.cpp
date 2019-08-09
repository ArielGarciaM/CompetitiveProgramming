#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 505;
const ll INF = 2e18;
ll dp[MAX][MAX], val[MAX];

void calc(int m, int L, int R, int oL, int oR) {
    if(L > R) return;
    int mi = (L + R)/2;
    dp[m][mi] = INF;
    int opt = -1;
    for(int o = max(0, oL); o <= min(mi - 1, oR); o++) {
        if(dp[m][mi] > dp[m - 1][o] + val[mi - o]) {
            dp[m][mi] = dp[m - 1][o] + val[mi - o];
            opt = o;
        }
    }
    //cout << m << " " << mi << " " << dp[m][mi] << '\n';
    calc(m, L, mi - 1, oL, opt);
    calc(m, mi + 1, R, opt, oR);
}

ll test_case() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        dp[0][i] = INF;
    for(int i = 1; i <= n; i++)
        calc(i, 0, n, 0, n - 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if(dp[y][x] < INF)
            cout << dp[y][x] << '\n';
        else
            cout << "impossible\n";
    }
}

int main() {
    freopen("jacking.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << '\n';
        test_case();
    }
}
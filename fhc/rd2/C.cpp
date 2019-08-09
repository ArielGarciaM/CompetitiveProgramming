#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 305;
char board[MAXN][MAXN];
int dp[MAXN][MAXN], costA[MAXN][MAXN], costB[MAXN][MAXN];
vector<int> v;

int calc(int L, int k) {
    if(k < 0)
        return 100000000;
    if(dp[L][k] != -1) {
        //cout << "dp(" << L << ", " << R << ", " << k << ") = " << dp[L][R][k] << endl;
        return dp[L][k];
    }
    if(v.size() - 1 - L + 1 <= k)  {
        //cout << "dp(" << L << ", " << R << ", " << k << ") = " << 0 << endl;
        return dp[L][k] = 0;
    }
    dp[L][k] = 10000000;
    if(L > 0)
        dp[L][k] = min(dp[L][k], v[L] + calc(L + 1, k));
    int cost = 0;
    for(int i = L; i <= v.size() - 1; i += 2) {
        //cout << L << ", " << R << ", " << k << " " << calc(i + 1, R, k - 1) << " " << cost << endl;
        dp[L][k] = min(dp[L][k], calc(i + 1, k - 1) + cost);
        cost += v[i + 1];
        //cout << cost << endl;
    }
    //cout << "dp(" << L << ", " << R << ", " << k << ") = " << dp[L][R][k] << endl;
    return dp[L][k];
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];

    for(int j = 1; j <= m; j++)
        board[0][j] = 'A';

    for(int j = 1; j <= m; j++) {
        string s = "";
        for(int i = 0; i <= n; i++)
            s += board[i][j];
        s += '$';
        //cout << s << endl;
        v.clear();
        int ct = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[i - 1]) {
                v.push_back(ct);
                ct = 1;
            }
            else
                ct++;
        }
        //for(auto x : v)
        //    cout << x << " ";
        //cout << endl;
        for(int p = 0; p < MAXN; p++)
            for(int r = 0; r < MAXN; r++)
                dp[p][r] = -1;
        for(int k = 0; k <= n + 1; k++) {
            costA[j][k] = calc(0, k);
            //cout << "COST A at " << j << ", " << k << " = " << costA[j][k] << endl;
        }
    }

    for(int j = 1; j <= m; j++)
        board[0][j] = 'B';

    for(int j = 1; j <= m; j++) {
        string s = "";
        for(int i = 0; i <= n; i++)
            s += board[i][j];
        s += '$';
        //cout << s << endl;
        v.clear();
        int ct = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[i - 1]) {
                v.push_back(ct);
                ct = 1;
            }
            else
                ct++;
        }
        //for(auto x : v)
        //    cout << x << " ";
        //cout << endl;
        for(int p = 0; p < MAXN; p++)
            for(int r = 0; r < MAXN; r++)
                dp[p][r] = -1;
        for(int k = 0; k <= n + 1; k++) {
            costB[j][k] = calc(0, k);
            //cout << "COST B at " << j << ", " << k << " = " << costB[j][k] << endl;
        }
    }

    while(q--) {
        int loss;
        cin >> loss;
        int lo = 1, hi = n + 1;
        while(lo < hi) {
            bool good = false;
            int mi = (lo + hi) / 2, cost = 0;
            for(int i = 1; i <= m; i++)
                cost += costA[i][mi];
            //cout << "mi = " << mi << " " << "cost = " << cost << endl;
            if(cost <= loss)
                good = true;
            cost = 0;
            for(int i = 1; i <= m; i++)
                cost += costB[i][mi];
            //cout << "mi = " << mi << " " << "cost = " << cost << endl;
            if(cost <= loss)
                good = true;
            if(good)
                hi = mi;
            else
                lo = mi + 1;
        }
        cout << lo << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        solve();
        cout << '\n';
    }
}
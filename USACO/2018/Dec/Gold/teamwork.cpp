#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXK = 1e3 + 5;
int dp[MAXN][MAXK], dpmax[MAXN], skill[MAXN];
int n, k;

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> skill[i];
    dpmax[0] = 0;
    for(int pos = 1; pos <= n; pos++) {
        for(int end = 1; end <= k; end++) {
            if(end == 1) {
                dp[pos][end] = dpmax[pos - 1] + skill[pos];
                dpmax[pos] = max(dpmax[pos], dp[pos][end]);
                //cout << pos << " " << end << " " << dp[pos][end] << endl;
                continue;
            }
            if(pos < end) {
                //cout << pos << " " << end << " 0\n";
                continue;
            }
            int mx = (dp[pos - 1][end - 1] - dpmax[max(pos - end, 0)])/(end - 1);
            int val = max(mx, skill[pos]);
            dp[pos][end] = dpmax[max(pos - end, 0)] + val*end;
            dpmax[pos] = max(dpmax[pos], dp[pos][end]);
            //cout << pos << " " << end << " " << dp[pos][end] << endl;
        }
    }
    cout << dpmax[n] << endl;
}
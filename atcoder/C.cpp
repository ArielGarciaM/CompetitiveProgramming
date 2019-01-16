#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int dp[MAXN][3], happ[MAXN][3];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> happ[i][0] >> happ[i][1] >> happ[i][2];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(k == j)
                    continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + happ[i][j]);
            }
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}
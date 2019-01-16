#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e3 + 5;
const ll MOD = 1e9 + 7;
ll dp[MAXN][MAXN];
char board[MAXN][MAXN];

int main() {
    int H, W;
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < W; j++)
            board[i][j] = s[j];
    }
    dp[0][0] = 1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(board[i][j] == '#')
                continue;
            if(i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if(j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[H - 1][W - 1] << endl;
}
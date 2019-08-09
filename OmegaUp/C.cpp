#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 305;
const ll INF = 1e15;
int n, m;
ll x1, yy, x2, y2;
ll best = -INF;
ll board[MAXN][MAXN], pref[MAXN][MAXN], mboard[MAXN][MAXN], dp[MAXN], val[MAXN], pew[MAXN];
int mask[MAXN][MAXN];
vector<ll> v;

void find_ans() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            mboard[i][j] = (mask[i][j] ? board[i][j] : -INF);
            pref[i][j] = pref[i][j - 1] + mboard[i][j];
        }
    }
    for(int l = 1; l <= m; l++) {
        for(int r = l; r <= m; r++) {
            for(int k = 1; k <= n; k++)
                val[k] = pref[k][r] - pref[k][l - 1];
            val[0] = -1;
            for(int k = 1; k <= n; k++) {
                dp[k] = val[k];
                pew[k] = k;
                if(dp[k - 1] + val[k] > dp[k]) {
                    dp[k] = dp[k - 1] + val[k];
                    pew[k] = pew[k - 1];
                }
                if(dp[k] > best) {
                    best = dp[k];
                    yy = l;
                    x1 = pew[k];
                    y2 = r;
                    x2 = k;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mask[i][j];
            if((i + j) % 2)
                mask[i][j] = 1 - mask[i][j];
        }
    }
    find_ans();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            mask[i][j] = 1 - mask[i][j];
        }
    }
    find_ans();
    cout << x1 - 1 << " " << yy - 1 << "\n" << x2 - 1 << " " << y2 - 1 << endl;
}
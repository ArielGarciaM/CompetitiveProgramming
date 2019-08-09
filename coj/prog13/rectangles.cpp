#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 355;
char board[MAXN][MAXN];
int rsz[MAXN][MAXN], dsz[MAXN][MAXN], n, m;
ll BIT[MAXN][MAXN];
vector<ii> bdsz[MAXN];

void upd(int t, int p, int v) {
    for(;p < MAXN; p += (p & -p)) BIT[t][p] += v;
}

ll sum(int t, int p) {
    ll res = 0;
    for(;p > 0; p -= (p & -p)) res += BIT[t][p];
    return res;
}

void test_case() {
    memset(rsz, 0, sizeof rsz);
    memset(dsz, 0, sizeof dsz);
    memset(BIT, 0, sizeof BIT);
    for(int i = 0; i < MAXN; i++)
        bdsz[i].clear();

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];

    for(int i = n; i > 0; i--) {
        for(int j = m; j > 0; j--) {
            if(board[i][j] == '.') {
                dsz[i][j] = rsz[i][j] = 0;
                continue;
            }
            dsz[i][j] = rsz[i][j] = 1;
            if(j < m) rsz[i][j] += rsz[i][j + 1];
            if(i < n) dsz[i][j] += dsz[i + 1][j];
            bdsz[dsz[i][j]].push_back({i, j});
        }
    }

    ll ans = 0;

    for(int d = n - 1; d >= 2; d--) {
        for(auto p : bdsz[d + 1]) {
            //cout << "added " << p.first << " " << p.second << endl;
            upd(p.first, p.second, 1);
        }
        for(int i = 1; i + d <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(dsz[i][j] < d + 1) continue;
                int r = min(rsz[i][j], rsz[i + d][j]);
                //cout << i << " " << i + d << " " << n << " " << j << " " << r << '\n';
                if(r < 3) continue;
                ans += (sum(i, j + r - 1) - sum(i, j + 1));
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    while(cin >> n >> m)
        test_case();
}
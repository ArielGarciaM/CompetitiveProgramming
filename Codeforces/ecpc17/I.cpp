#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,fma")
using namespace std;

const int MAXN = 202;
const int MAXV = 2002;
int board[MAXN][MAXN], cnt[MAXV][MAXN][MAXN], ans[100000 + 5];

inline void test_case() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
            cnt[board[i][j]][i][j]++;
        }
    }
    for(int d = 1; d < MAXV; d++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cnt[d][i][j] += cnt[d][i-1][j] + cnt[d][i][j - 1] - cnt[d][i - 1][j - 1];
            }
        }
    }
    for(int d = 1; d < MAXV; d++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cnt[d][i][j] += cnt[d - 1][i][j];
            }
        }
    }
    for(int i = 0; i < q; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        int sz = (C - A + 1)*(D - B + 1)/2;
        int lo = 1, hi = 2000;
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(cnt[mi][C][D] - cnt[mi][C][B - 1] - cnt[mi][A - 1][D] + cnt[mi][A - 1][B - 1] > sz)
                hi = mi;
            else
                lo = mi + 1;
        }
        ans[i] = lo;
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("important.in", "r", stdin);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        test_case();
    }
}
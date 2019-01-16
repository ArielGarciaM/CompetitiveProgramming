#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAXN = 1005;
const int MAXK = 1005;
const ll INF = 1e16;

struct line {
    ll m, b;
    ll eval(ll x) { return m*x + b; }
    ld intersectX(line l) { return (ld) (b - l.b)/(l.m - m);}
};

ll chtinsert(line l, deque<line> &dq) {
    while(dq.size() >= 2 && l.intersectX(dq[0]) >= dq[0].intersectX(dq[1]))
        dq.pop_front();
    dq.push_front(l);
}

ll chtquery(ll x, deque<line> &dq) {
    while(dq.size() >= 2 && dq.back().eval(x) <= dq[dq.size() - 2].eval(x))
        dq.pop_back();
    return dq.back().eval(x);
}

int main() {
    int n, k;
    while(cin >> n >> k) {
        ll dp[MAXN][MAXK];
        ll X[MAXN], W[MAXN], pref[MAXN];
        pref[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> X[i] >> W[i];
            pref[i] = pref[i - 1] + W[i];
        }
        for(int i = 0; i < MAXN; i++) {
            for(int j = 0; j < MAXN; j++)
                dp[i][j] = INF;
        }
        dp[n][1] = pref[n]*X[n];
        deque<line> cht[k + 1];
        for(int pos = n; pos >= 1; pos--) {
            for(int cnt = 1; cnt <= k; cnt++) {
                if(pos < n) {
                    if(cnt == 1)
                        continue;
                    dp[pos][cnt] = X[pos]*pref[pos] - chtquery(pref[pos], cht[cnt - 1]);
                }
                line l = {X[pos], -dp[pos][cnt]};
                chtinsert(l, cht[cnt]);
            }
        }
        ll mn = INF;
        for(int p = 1; p <= n; p++) {
            if(dp[p][k] < mn)
                mn = dp[p][k];
        }
        for(int p = 1; p <= n; p++)
            mn -= X[p]*W[p];
        cout << mn << endl;
    }
}
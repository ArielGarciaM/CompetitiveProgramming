#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 1e9 + 7;
const ll MAXN = 1005;
set<ii> allpts;
vector<ii> pts;
map<ii, int> cnt;

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b)%MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll ans[MAXN], fac[MAXN], ifac[MAXN];

ll binom(ll n, ll k) {
    ll den = (ifac[k] * ifac[n - k]) % MOD;
    return (fac[n] * den) % MOD;
}

int main() {
    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    ifac[MAXN - 1] = mpow(fac[MAXN - 1], MOD - 2);
    for(ll i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % MOD;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts.push_back({x, y});
        allpts.insert({pts[i].first * 2, pts[i].second * 2});
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            auto p = pts[i], q = pts[j];
            cnt[{p.first + q.first, p.second + q.second}]++;
        }
    }

    for(auto p : cnt) {
        auto point = p.first;
        int m = p.second;
        for(int i = 0; i <= m; i++)
            ans[2*i] = (ans[2*i] + binom(m, i)) % MOD;
        if(allpts.count(point))
            for(int i = 0; i <= m; i++)
                ans[2*i + 1] = (ans[2*i + 1] + binom(m, i)) % MOD;
    }
    ans[1] = n;
    for(int i = 1; i <= n; i++) {
        if(i > 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
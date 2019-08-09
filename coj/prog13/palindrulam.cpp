#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXU = 3e5;
int ways[MAXU], isulam[MAXU], n;
vector<int> ulams;

const int MAXN = 5e5 + 12;
const ll P = 37;
const ll MOD = 1e9 + 9;
ll pex[MAXN], pinv[MAXN], BIT[2][MAXN];

ll mexp(ll b, ll e) {
    if(e == 0) return 1;
    if(e % 2) return (b * mexp(b, e - 1))%MOD;
    ll p = mexp(b, e/2);
    return (p * p)%MOD;
}

void upd(int t, int p, ll v) {
    for(; p < MAXN; p += (p & -p))
        BIT[t][p] = (BIT[t][p] + v)%MOD;
}

ll sum(int t, int p) {
    ll res = 0;
    for(; p > 0; p -= (p & -p))
        res += BIT[t][p];
    return res % MOD;
}

void test_case() {
    memset(BIT, 0, sizeof BIT);
    vector<ll> a(n);
    for(auto &x : a)
        cin >> x;
    for(int i = 1; i <= n; i++)
        upd(0, i, pex[i - 1] * a[i - 1]);
    reverse(a.begin(), a.end());
    for(int i = 1; i <= n; i++)
        upd(1, i, pex[i - 1] * a[i - 1]);
    reverse(a.begin(), a.end());
    int q;
    cin >> q;
    while(q--) {
        char t;
        int x, y;
        cin >> t >> x >> y;
        if(t == 'G') {
            if(!isulam[a[x - 1]] && !isulam[a[y - 1]]) {
                cout << "N\n";
                continue;
            }
            ll h1 = sum(0, y) - sum(0, x - 1);
            h1 = (h1 * pinv[x - 1])%MOD;
            x = n + 1 - x;
            y = n + 1 - y;
            ll h2 = sum(1, x) - sum(1, y - 1);
            h2 = (h2 * pinv[y - 1])%MOD;
            if(h1 < 0)
                h1 += MOD;
            if(h2 < 0)
                h2 += MOD;
            cout << (h1 == h2 ? "Y\n" : "N\n");
        }
        else {
            ll u = y;
            ll d = u - a[x - 1];
            d = (d * pex[x - 1])%MOD;
            upd(0, x, d);
            d = u - a[x - 1];
            d = (d * pex[n - x])%MOD;
            upd(1, n + 1 - x, d);
            a[x - 1] = u;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ulams.push_back(1);
    ulams.push_back(2);
    isulam[2] = isulam[1] = 1;
    ways[3] = 1;
    while(ulams.size() < 10000) {
        int k = ulams.back() + 1;
        for(;;k++) if(ways[k] == 1) break;
        for(auto x : ulams) ways[k + x]++;
        isulam[k] = 1;
        ulams.push_back(k);
    }
    pex[0] = 1;
    for(int i = 1; i < MAXN; i++)
        pex[i] = (P * pex[i - 1])%MOD;
    pinv[MAXN - 1] = mexp(pex[MAXN - 1], MOD - 2);
    for(int i = MAXN - 2; i >= 0; i--)
        pinv[i] = (P * pinv[i + 1])%MOD;

    while(cin >> n)
        test_case();
}
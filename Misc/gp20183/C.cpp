#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e5 + 5;
ll BIT[MAXN];

void upd (int p, ll v) {
    for(; p < MAXN; p += (p & -p))
        BIT[p] += v;
}

ll sum (int p) {
    ll res = 0;
    for(; p > 0; p -= (p & -p))
        res += BIT[p];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    ll H, V, ans = 0;
    cin >> H >> V;
    ans = (H + 1ll) * (V + 1ll);
    vector<ii> v;
    while(H--) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    vector<int> l;
    for(auto p : v)
        l.push_back(p.second);
    vector<int> sl = l;
    sort(sl.begin(), sl.end());
    gp_hash_table<int, int> mp;
    for(int i = 0; i < sl.size(); i++)
        mp[sl[i]] = i + 1;
    for(auto x : l) {
        x = mp[x];
        ans += (sum(MAXN - 1) - sum(x - 1));
        upd(x, 1);
    }
    v.clear();
    l.clear();
    mp.clear();
    memset(BIT, 0, sizeof BIT);
    while(V--) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    for(auto p : v)
        l.push_back(p.second);
    sl = l;
    sort(sl.begin(), sl.end());
    for(int i = 0; i < sl.size(); i++)
        mp[sl[i]] = i + 1;
    for(auto x : l) {
        x = mp[x];
        ans += (sum(MAXN - 1) - sum(x - 1));
        upd(x, 1);
    }
    cout << ans << endl;
}
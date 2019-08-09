#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

const int MAXN = 1e6 + 5;
ll BIT[MAXN];

void add(ll p, ll v) {
    for(;p < MAXN; p += (p & -p))
        BIT[p] += v;
}

ll sum(ll p) {
    ll res = 0;
    for(;p > 0; p -= (p & -p))
        res += BIT[p];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n), pref(n + 1);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    ll p;
    cin >> p;
    for(int i = 0; i < n; i++)
        v[i] -= p;
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + v[i - 1];
    vector<ll> spf = pref;
    gp_hash_table<ll, int> code;
    int ct = 1;
    sort(spf.begin(), spf.end());
    for(int i = 0; i <= n; i++) {
        if(i == 0 || spf[i] > spf[i - 1])
            code[spf[i]] = ct++;
    }
    for(int i = 0; i <= n; i++)
        pref[i] = code[pref[i]];
    //for(int i = 0; i <= n; i++)
    //    cout << pref[i] << " ";
    //cout << endl;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += sum(pref[i]);
        add(pref[i], 1);
    }
    cout << ans << endl;
}
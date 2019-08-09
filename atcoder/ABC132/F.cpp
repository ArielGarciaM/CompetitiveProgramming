#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<ii> range;
vector<int> len;
vector<ll> val;
int n, k;

const ll MOD = 1e9 + 7;

ll bnd(vector<ll> &v, vector<ll> &psum, int len) {
    int lo = 0, hi = range.size() - 1;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(len >= range[mi].first)
            lo = mi;
        else
            hi = mi - 1;
    }
    //cout << range[lo].first << " <= " << len << " <= " << range[lo].second << endl;
    ll ans = (lo ? psum[lo - 1] : 0), ct = (len - range[lo].first + 1);
    //cout << ans << endl;
    ct = (ct * v[lo])%MOD;
    return (ans + ct)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    int pos = 1;
    while(pos <= n) {
        int x = n / pos, y = n / x;
        range.push_back({pos, y});
        len.push_back(x);
        val.push_back(1);
        pos = y + 1;
    }
    //for(int i = 0; i < range.size(); i++)
    //    cout << "(" << range[i].first << ", " << range[i].second << ") " << len[i] << '\n';
    for(int i = 0; i < k - 1; i++) {
        vector<ll> cv = val;
        vector<ll> psum(cv);
        for(int j = 1; j < psum.size(); j++)
            psum[j] = (psum[j]*(range[j].second - range[j].first + 1) + psum[j - 1]) % MOD;
        for(int j = 0; j < val.size(); j++) {
            //cout << len[j] << " " << bnd(cv, psum, len[j]) << endl;
            val[j] = bnd(cv, psum, len[j]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < range.size(); i++) {
        ll len = range[i].second - range[i].first + 1;
        ans = (ans + len * val[i]) % MOD;
    }
    cout << ans << endl;
}
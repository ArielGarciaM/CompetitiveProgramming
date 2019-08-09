#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 42;
int prime[MAXN], mfr[MAXN], sz[MAXN], numchoices;
vector<int> vld[MAXN];
map<ii, int> freq;
map<ii, ll> mx;
map<int, int> back;

ll mpow(ll b, ll e, ll m) {
    if(e == 0) return 1;
    if(e % 2) return (b * mpow(b, e - 1, m))%m;
    ll p = mpow(b, e/2, m);
    return (p * p)%m;
}

ll minv(ll b, ll m) {
    return mpow(b, m - 2, m);
}

ll check(ll rep) {
    vector<ii> v;
    ll pos = 0;
    for(int i = 0; i < numchoices; i++) {
        ll cu = sz[i];
        ll t = rep % cu;
        rep /= cu;
        v.push_back({prime[i], vld[i][t]});
    }
    for(auto pr : v) {
        pos = max(pos, mx[pr]);
        //cout << pr.first << " " << pr.second << endl;
    }
    ll add = 1;
    for(auto pr : v) {
        ll p = pr.first, x = pr.second;
        // pos + add*k = x (mod p)
        // k = (x - pos)/add
        ll ia = minv(add, p);
        ll y = (x - pos)%p;
        if(y < 0) y += p;
        ll k = (y * ia)%p;
        pos += add*k;
        add *= p;
    }
    return pos;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x, p;
        cin >> x >> p;
        freq[{p, x%p}]++;
        mx[{p, x%p}] = max(mx[{p, x%p}], x);
    }
    int curp = 0, curptr = 0;
    for(auto it : freq) {
        auto pr = it.first;
        if(pr.first != curp) {
            curp = pr.first;
            prime[curptr] = curp;
            back[curp] = curptr;
            curptr++;
        }
    }
    for(auto it : freq) {
        auto pr = it.first;
        mfr[back[pr.first]] = max(mfr[back[pr.first]], it.second);
    }
    for(auto it : freq) {
        auto pr = it.first;
        int x = back[pr.first];
        if(it.second != mfr[x])
            continue;
        vld[x].push_back(pr.second);
    }
    int tot = 1, ht = 0;
    for(int i = 0; i < curptr; i++) {
        ht += mfr[i];
        sz[i] = vld[i].size();
        tot *= sz[i];
        //cout << prime[i] << endl;
        //for(auto x : vld[i]) cout << x << " ";
        //cout << '\n';
    }
    ll ans = LLONG_MAX;
    numchoices = curptr;
    //cout << ht << endl;
    for(int i = 0; i < tot; i++) {
        ans = min(ans, check(i));
    }
    cout << ans << " " << ht << endl;
}
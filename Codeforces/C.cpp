#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll h[MAXN], nfree[MAXN];
ll n, s;

bool check(ll bf) {
    ll ms = 0, bfp = 1, ren = n;
    for(ll i = 1; ren > 0; i++) {
        ms += i*min(bfp, ren);
        ren -= min(bfp, ren);
        bfp *= bf;
    }
    return (ms <= s);
}

ll bs() {
    ll lo = 1, hi = n;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(!check(mi))
            lo = mi + 1;
        else
            hi = mi;
    }
    return lo;
}

int main() {
    cin >> n >> s;
    if(s < 2*n - 1 || s > n*(n + 1ll)/2ll) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    ll cs = n*(n + 1ll)/2ll;
    ll mxlev = n, mnfree = 1, bf = 1;
    for(int i = 1; i <= n; i++)
        h[i] = 1;
    bf = bs();
    while(cs > s) {
        ll ml = 1;
        bool done = false;
        for(ll lv = 1; lv < mxlev; lv++) {
            if(h[lv] < ml && cs - s >= mxlev - lv) {
                ll delta = min({h[mxlev], ml - h[lv], (cs - s)/(mxlev - lv)});
                cs -= delta*(mxlev - lv);
                h[mxlev] -= delta;
                h[lv] += delta;
                if(h[mxlev] == 0)
                    mxlev--;
            }
            ml *= bf;
            if(ml > 1e7)
                ml = 1e7;
        }
    }
    int ifst = 1;
    for(int i = 2; i <= mxlev; i++) {
        int cnt = 0, cn = ifst;
        for(int j = 0; j < h[i]; j++) {
            if(cnt >= bf) {
                cnt = 0;
                cn++;
            }
            cout << cn << " ";
            cnt++;
        }
        ifst += h[i - 1];
    }
    cout << endl;
}
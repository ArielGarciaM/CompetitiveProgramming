#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll L, C;

ll f(ll b) {
    return (b*(b + 1ll))/2ll + (b + 1ll)*(L + 1ll) + ((b*(b + 1ll))/2ll + (b*(b + 1ll)*(2ll*b + 1))/6ll)/2ll;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> L >> C;
        if(C <= L) {
            cout << C << endl;
            continue;
        }
        ll lo = 0, hi = 1e6;
        while(lo < hi) {
            ll mi = (lo + hi + 1)/2;
            if(f(mi) <= C)
                lo = mi;
            else
                hi = mi - 1;
        }
        ll k = lo, d = C - f(k);
        cout << -k + d - 1 << endl;
    }
}
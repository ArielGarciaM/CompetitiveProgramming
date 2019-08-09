#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e15;

bool over(ll a, ll b) {
    return a > INF/b;
}

int main() {
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    if(n == 1 && m == 1) {
        cout << "1\n";
        return 0;
    }
    if(n == 1) {
        cout << min(m, 1 + k/x) << endl;
        return 0;
    }
    if(m == 1) {
        cout << min(n, 1 + k/y) << endl;
        return 0;
    }
    if(x > y) {
        swap(x, y);
        swap(m, n);
    }
    if(k < (m - 1)*x) {
        cout << 1 + k/x << endl;
        return 0;
    }
    k -= ((m - 1)*x);
    ll ans = m, rcost = ((m - 1)*x) + y;
    ll lo = 0, hi = (1LL<<32LL) - 1;
    while(lo < hi) {
        ll mi = (lo + hi + 1)/2;
        if(over(mi, rcost) || rcost*mi > k)
            hi = mi - 1;
        else
            lo = mi;
    }
    k -= rcost*lo;
    ans += m*lo;
    if(k >= y) {
        k -= y;
        ans++,
        ans += k/x;
    }
    cout << min(ans, n*m) << endl;
}
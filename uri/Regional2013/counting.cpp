#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll x) {
    if(x == 0)
        return 0;
    ll p = 63 - __builtin_clzll(x);
    ll y = ((1ll << p) - 1) & x;
    return p*(1ll << (p - 1ll)) + y + 1 + solve(y);
}

int main() {
    ll a, b;
    while(cin >> a >> b) {
        cout << solve(b) - solve(a - 1) << endl;
    }
}

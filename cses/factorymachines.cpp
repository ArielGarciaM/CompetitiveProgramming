#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
vector<ll> v;
int t;

bool check(ll m) {
    ll tot = 0;
    for(auto x : v) {
        tot += m/x;
        tot = min(tot, INF);
    }
    return tot >= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> t;
    v.resize(n);
    for(auto &x : v)
        cin >> x;
    ll lo = 1, hi = INF;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(check(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << lo << '\n';
}
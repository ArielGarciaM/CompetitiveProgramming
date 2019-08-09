#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
int n;

bool check(ll rnd) {
    ll bnd = v[0] - rnd, moves = 0;
    for(int i = 1; i < n - 1; i++) {
        if(v[i] <= bnd)
            break;
        ll diff = v[i] - v[i + 1];
        if(diff == 0)
            continue;
        ll lg = 31 - __builtin_clz(i);
        ll delta = diff*(lg + 1ll);
        if(moves <= LLONG_MAX - delta)
            moves += delta;
        else
            moves = LLONG_MAX;
        if(moves > rnd)
            return false;
    }
    if(v[n - 1] > bnd) {
        ll lg = 31 - __builtin_clz(n - 1);
        ll delta = (v[n - 1] - bnd)*(lg + 1ll);
        if(moves <= LLONG_MAX - delta)
            moves += delta;
        else
            moves = LLONG_MAX;
    }
    if(moves > rnd)
        return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    v.resize(n);
    for(auto &x : v) cin >> x;
    sort(v.rbegin(), v.rend());
    ll lo = 0, hi = 1e18;
    while(lo < hi) {
        ll mi = (lo + hi + 1)/2ll;
        if(check(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << endl;
}
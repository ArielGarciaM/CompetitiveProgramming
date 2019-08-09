#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<ll> v;

bool check(ll sum) {
    ll rem = 0;
    int gp = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] <= rem)
            rem -= v[i];
        else {
            gp++;
            rem = sum - v[i];
        }
    }
    return (gp <= k);
}

int main() {
    cin >> n >> k;
    v.resize(n);
    for(auto &x : v)
        cin >> x;
    ll lo = *max_element(v.begin(), v.end()), hi = 1e15;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(check(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << hi << endl;
}
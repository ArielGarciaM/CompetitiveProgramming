#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> p3;
map<ll, vector<ll>> memo;

vector<ll> solve(ll n) {
    if(n == 0)
        return {};
    if(memo.count(n))
        return memo[n];
    if(n % 2 == 0) {
        vector<ll> v, ans;
        v = solve(n / 2);
        for(auto x : v)
            ans.push_back(2ll*x);
        return memo[n] = ans;
    }
    ll po = 0;
    for(int i = p3.size() - 1; i >= 0; i--) {
        if(p3[i] <= n) {
            po = p3[i];
            break;
        }
    }
    vector<ll> v = solve(n - po);
    v.push_back(po);
    return memo[n] = v;
}

int main() {
    freopen("distribution.in", "r", stdin);
    freopen("distribution.out", "w", stdout);
    ll p = 1;
    while(p < 1e18) {
        p3.push_back(p);
        p *= 3ll;
    }
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> v = solve(n);
        cout << v.size() << '\n';
        for(auto x : v)
            cout << x << " ";
        cout << '\n';
    }
}
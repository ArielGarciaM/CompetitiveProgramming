#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    ll sum = accumulate(v.begin(), v.end(), 0LL), big = *max_element(v.begin(), v.end());
    cout << sum + max(0LL, 2*big - sum) << '\n';
}
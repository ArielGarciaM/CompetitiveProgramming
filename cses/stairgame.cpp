#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    for(int i = 1; i < n; i += 2) res ^= v[i];
    cout << (res ? "first\n" : "second\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}
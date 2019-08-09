#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll result = 0, elapsed = 0;
    int n;
    cin >> n;
    vector<ll> times;
    for(int i = 0; i < n; i++) {
        ll a, d;
        cin >> a >> d;
        result += d;
        times.push_back(a);
    }
    sort(times.begin(), times.end());
    for(auto x : times) {
        elapsed += x;
        result -= elapsed;
    }
    cout << result << '\n';
}
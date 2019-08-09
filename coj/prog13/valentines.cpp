#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void test_case() {
    ll a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    if(a > b)
        swap(a, b);
    vector<ll> v = {x, y, z};
    sort(v.begin(), v.end());
    do {
        ll p = v[0], q = v[1], r = v[2];
        ll s = p + q + q;
        ll t = r + q + r + q;
        if(min(s, t) <= a && max(s, t) <= b) {
            cout << "POSSIBLE\n";
            return;
        }
        s = p + q;
        t = r + q + r + p + r;
        if(min(s, t) <= a && max(s, t) <= b) {
            cout << "POSSIBLE\n";
            return;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    while(m--) {
        ll num, k;
        cin >> num >> k;
        k %= n;
        while(k--) {
            num <<= 1ll;
            num |= ((num & (1ll << n)) >> n);
            num &= ~(1ll << n);
        }
        cout << num << endl;
    }
}
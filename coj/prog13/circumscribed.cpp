#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll r, k;
        cin >> r >> k;
        if(k % 2)
            cout << (r*r*(1LL << (k - 1)/2ll)) << "PI\n";
        else
            cout << (r*r*(1LL << (k/2 + 1))) << '\n';
    }
}
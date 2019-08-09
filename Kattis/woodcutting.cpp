#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for(auto &x : v) {
            x = 0;
            int am;
            cin >> am;
            while(am--) {
                ll w;
                cin >> w;
                x += w;
            }
        }
        sort(v.begin(), v.end());
        ll ti = 0, to = 0;
        for(auto x : v) {
            ti += x;
            to += ti;
        }
        cout << (double)to/(double)n << '\n';
    }
}
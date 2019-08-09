#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    while(cin >> n >> k) {
        vector<ll> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        ll lo = *max_element(v.begin(), v.end()), hi = 1e14;
        while(lo < hi) {
            ll mi = (lo + hi)/2;
            ll sum = 0, cnt = 1;
            for(int i = 0; i < n; i++) {
                if(sum + v[i] <= mi)
                    sum += v[i];
                else {
                    sum = v[i];
                    cnt++;
                }
            }
            if(cnt <= k)
                hi = mi;
            else
                lo = mi + 1;
        }
        cout << lo << '\n';
    }
}
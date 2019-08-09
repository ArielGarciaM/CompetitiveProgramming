#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rev(ll x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll cnt = 0;
    for(ll n = 1; n <= 1000000000; n++) {
        if(n % 10 == 0)
            continue;
        if(rev(n*n) == rev(n)*rev(n)) {
            cnt++;
            cout << n << '\n';
        }
    }
    cout << "total = " << cnt << '\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        ll n, t, x, y, z;
        cin >> n >> t >> x >> y >> z;
        if(t == 2 || t == 4) {
            if(x == z) {
                cout << "0 1\n";
                continue;
            }
            ll num = 2*(n - y) + 1;
            ll den = 2*n + 1;
            ll d = __gcd(num, den);
            num /= d, den /= d;
            cout << num << " " << den << endl;
            continue;
        }
        if(t == 1) {
            swap(x, z);
            t = 3;
        }
        ll num, den;
        if(x == 0) {
            num = (z > y ? 0 : 1);
            den = 1;
            cout << num << " " << den << endl;
            continue;
        }
        den = 2*n + 1;
        if(z == x)
            num = x;
        else
            num = (2*n - x + 1);
        ll d = __gcd(num, den);
        num /= d, den /= d;
        cout << num << " " << den << endl;
    }
}
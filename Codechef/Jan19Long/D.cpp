#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, p;
        cin >> n >> p;
        if(n % 2) {
            if(n == 1) {
                cout << p * p * p << endl;
                continue;
            }
            ll m = n / 2;
            cout << (p - m)*(p - m) + (p - n)*(p - m) + (p - n)*(p - n) << endl;
        }
        else {
            if(n == 2) {
                cout << p * p * p << endl;
                continue;
            }
            ll m = n /2;
            cout << (p - m + 1ll)*(p - m + 1ll) + (p - n)*(p - m + 1ll) + (p - n)*(p - n) << endl;
        }
    }
}
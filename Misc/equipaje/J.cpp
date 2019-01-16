#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long double ans = 0.0;
    while(n--) {
        long double x;
        cin >> x;
        ans += (x == 0.0 ? 2.0 : 1.0/x);
    }
    cout << fixed << setprecision(20) << ans << endl;
}
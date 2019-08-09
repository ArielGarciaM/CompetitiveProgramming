#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        ans += x * y;
    }
    cout << fixed << setprecision(10) << ans << endl;
}
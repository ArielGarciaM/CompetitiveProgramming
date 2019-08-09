#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int d = min(a, b);
        a -= d;
        b -= d;
        cout << 1 + d + (int)((ld)a*log10(2) + (ld)b*log10(5)) << '\n';
    }
}
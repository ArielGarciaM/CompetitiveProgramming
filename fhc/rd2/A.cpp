#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char solve() {
    int n, m, k, a, b, x1, y1, x2, y2;
    cin >> n >> m >> k >> a >> b >> x1 >> y1;
    if(k == 1)
        return 'N';
    cin >> x2 >> y2;
    int p = (x1 + y1)%2, q = (x2 + y2)%2, r = (a + b)%2;
    if(p != q || p != r)
        return 'N';
    return 'Y';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": " << solve() << '\n';
    }
}
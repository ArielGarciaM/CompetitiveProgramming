#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
const int LOG = 18;
int cmx[MAXN][LOG], dmx[MAXN][LOG];

int crmq(int l, int r) {
    int d = 31 - __builtin_clz(r - l + 1), x = (1 << d);
    //cout << l << " " << r << " " << d << " " << x << endl;
    return max(cmx[l][d], cmx[r - x + 1][d]);
}

int drmq(int l, int r) {
    int d = 31 - __builtin_clz(r - l + 1), x = (1 << d);
    return max(dmx[l][d], dmx[r - x + 1][d]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n, d;
        cin >> n >> d;
        for(int i = 0; i < n; i++)
            cin >> cmx[i][0];
        for(int i = 0; i < n; i++)
            cin >> dmx[i][0];
        for(int l = 0; l + 1 < LOG; l++) {
            for(int i = 0; i + (1 << l) < n; i++) {
                cmx[i][l + 1] = max(cmx[i][l], cmx[i + (1 << l)][l]);
                dmx[i][l + 1] = max(dmx[i][l], dmx[i + (1 << l)][l]);
            }
        }
        ll ans = 0;
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                int a = crmq(l, r), b = drmq(l, r);
                if(a <= b + d && b <= a + d) {
                    //cout << l << " " << r << " " << a << " " << b << endl;
                    ans++;
                }
            }
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}
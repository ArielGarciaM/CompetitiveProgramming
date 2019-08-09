#include <bits/stdc++.h>
using namespace std;
typedef double ld;

vector<ld> expe;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        ld y;
        cin >> x >> y;
        expe.push_back(((ld)x)*y);
    }
    ld ans = 0.0;
    sort(expe.rbegin(), expe.rend());
    for(int i = 1; i <= n; i++)
        ans += ((ld)i)*expe[i - 1];
    cout << fixed << setprecision(20) << ans/((ld)n) << endl;
}
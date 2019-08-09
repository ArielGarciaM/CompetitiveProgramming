#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, g;
    while(cin >> n >> g) {
        vector<int> d(n);
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            d[i] = y - x;
        }
        int ans = 0;
        sort(d.begin(), d.end());
        for(int i = 0; i < n; i++) {
            if(d[i] < 0) {
                ans += 3;
                continue;
            }
            if(g >= d[i] + 1) {
                g -= d[i] + 1;
                ans += 3;
                continue;
            }
            if(g >= d[i]) {
                g -= d[i];
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
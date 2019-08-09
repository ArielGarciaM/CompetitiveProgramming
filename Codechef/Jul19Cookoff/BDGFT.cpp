#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pref(n + 1);
    for(int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + (s[i] - '0');

    int ans = 0;
    for(int k = 1; k*k + k <= n; k++) {
        for(int i = 0; i + k*k + k <= n; i++) {
            if(pref[i + k*k + k] - pref[i] == k) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
}
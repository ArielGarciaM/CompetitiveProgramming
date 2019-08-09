#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        string s;
        vector<int> pre(n + 1);
        cin >> s;
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + (s[i - 1] - '0');
        int ans = 0;
        int len = (n + 1)/2;
        for(int i = len; i <= n; i++)
            ans = max(ans, pre[i] - pre[i - len]);
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}
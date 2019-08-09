#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for(int st = 0; st + m <= n; st++) {
        bool b = true;
        for(int i = 0; i < m; i++) {
            if(t[i] == s[st + i]) {
                b = false;
                break;
            }
        }
        if(b)
            ans++;
    }
    cout << ans << endl;
}
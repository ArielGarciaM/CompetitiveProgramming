#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {
        string s;
        cin >> s;
        int n = s.size() - 1, cb = 0;
        for(int i = 1; i <= n; i++)
            if(s[i] == 'B') cb++;
        char ans = 'Y';
        if(cb == n || cb == 0) ans = 'N';
        if(n > 3 && cb == 1) ans = 'N';
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}
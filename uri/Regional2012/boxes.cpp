#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll ans[105][205][205];

ll dp(ll mx, ll num, ll pass) {
    if(ans[mx][num][pass] != -1)
        return ans[mx][num][pass];

    if(mx == 0)
        return ((num == 0 && pass == 0) ? 1 : 0);

    ll d = dp(mx - 1, num, pass/2); 
    if(num > 0)
         d = (d + dp(mx, num - 1, pass + 1)) % MOD;
    ans[mx][num][pass] = d;
    return d;
}

int main() {
    for(int i = 0; i < 105; i++) {
        for(int j = 0; j < 205; j++) {
            for(int k = 0; k < 205; k++)
                ans[i][j][k] = -1;
        }
    }
    ll b, s;
    while(cin >> s >> b)
        cout << dp(b - 1, s, 0) << endl;
}
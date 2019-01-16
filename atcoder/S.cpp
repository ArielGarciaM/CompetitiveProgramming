#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXL = 1e4 + 5;
const int MAXD = 1e2 + 5;
const ll MOD = 1e9 + 7;
ll dp[MAXL][MAXD];

int main() {
    string s;
    int d;
    cin >> s >> d;
    int l = s.length();
    int sf = 0;
    dp[0][0] = 1;
    for(int i = 0; i < l; i++) {
        for(int res = 0; res < d; res++) {
            for(int dig = 0; dig < 10; dig++) {
                dp[i + 1][(res + dig) % d] = (dp[i + 1][(res + dig) % d] + dp[i][res]) % MOD;
            }
        }
        for(int dig = s[i] - '0' + 1; dig <= 9; dig++)
            dp[i + 1][(sf + dig)%d] = (dp[i + 1][(sf + dig) % d] - 1 + MOD) % MOD;
        sf += (s[i] - '0');
        sf %= d;
    }
    cout << (dp[l][0] + MOD - 1) % MOD << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll dp[1000001];

int main() {
    dp[0] = 1;
    for(int i = 1; i <= 1000000; i++) { 
        for(int j = max(i - 6, 0); j < i; j++) {
            dp[i] += dp[j];
            if(dp[i] > MOD)
                dp[i] -= MOD;
        }
    }
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}
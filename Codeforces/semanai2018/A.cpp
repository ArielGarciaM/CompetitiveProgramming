#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 2;

int main()
{
    int dp[MAXN];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    dp[7] = 64;
    dp[8] = 128;
    for(int i = 9; i < MAXN; i++)
    {
        for(int j = i - 8; j < i; j++)
            dp[i] = (dp[i] + dp[j]) % MOD;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << dp[n/3] << endl;
    }
}
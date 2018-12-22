#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
long long dp[MAXN][2*MAXN];

int main()
{
    long long q, n, d;
    cin >> q >> n >> d;
    string s1, s2;
    cin >> s1 >> s2;
    dp[0][0] = 1;
    for(int pos = 1; pos <= n; pos++)
    {
        if(s1[pos - 1] == s2[pos - 1])
        {
            for(int k = 0; k <= 2*n; k++)
            {
                dp[pos][k] = dp[pos - 1][k];
                if(k >= 2)
                    dp[pos][k] += (q - 1)*dp[pos - 1][k - 2];
            }
        }
        else
        {
            for(int k = 1; k <= 2*n; k++)
            {
                dp[pos][k] = 2ll*dp[pos - 1][k - 1];
                if(k >= 2)
                    dp[pos][k] += (q - 2)*dp[pos - 1][k - 2];
            }
        }
    }
    cout << dp[n][d] << endl;
}
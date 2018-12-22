#include <bits/stdc++.h>
using namespace std;

const int MAXN = 52;
const int MAXS = 201;
const int MOD = 1e9 + 7;

int main()
{
    map<int, int> ct;
    int n, A[MAXN];
    long long dp1[MAXN/2][MAXS][MAXN/2], dp2[MAXN/2][MAXS][MAXN/2], binom[MAXN][MAXN];
    binom[0][0] = 1;
    for(int i = 0; i < MAXN/2; i++)
    {
        if(i < MAXN - 1)
            binom[i][0] = binom[i][i] = 1;
        for(int j = 0; j < MAXS; j++)
        {
            for(int k = 0; k < MAXN/2; k++)
            {
                dp1[i][j][k] = 0;
                dp2[i][j][k] = 0;
            }
        }
    }
    for(int i = 2; i < MAXN; i++)
    {
        for(int j = 1; j < i; j++)
        {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j])%MOD;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        ct[A[i]]++;
    }
    dp1[0][0][0] = 1;
    dp2[0][0][0] = 1;
    for(int i = 1; i <= min(n, 50); i++)
    {
        int b = A[i - 1];
        for(int s = 0; s < MAXS; s++)
        {
            for(int k = 0; k <= min(n, 50); k++)
            {
                dp1[i][s][k] = dp1[i - 1][s][k];
                if(s >= b && k > 0)
                    dp1[i][s][k] = (dp1[i][s][k] + dp1[i - 1][s - b][k - 1])%MOD;

            }
        }
    }
    if(n > 50)
    {
        for(int i = 1; i <= n - 50; i++)
        {
            int b = A[i + 49];
            for(int s = 0; s < MAXS; s++)
            {
                for(int k = 0; k <= min(n - 50, 50); k++)
                {
                    dp2[i][s][k] = dp2[i - 1][s][k];
                    if(s >= b && k > 0)
                        dp2[i][s][k] = (dp2[i][s][k] + dp2[i - 1][s - b][k - 1])%MOD;

                }
            }
        }
    }
    /*for(int i = 0; i < 50; i++)
    {
        for(int k = 0; k <= 6; k++)
            cout << i << " " << k << " " << dp[n][i][k] << endl;
    }*/
    int ans = 0;
    for(auto p : ct)
    {
        int num = p.first, amt = p.second;
        for(int cop = 1; cop <= amt; cop++)
        {
            long long sum = num * cop, app = 0;
            for(int s = 0; s < min(sum + 1, (long long)MAXS); s++)
            {
                for(int k = 0; k <= cop; k++)
                {
                    /*if(sum == s && k == cop)
                    {
                        cout << "here u go: " << dp1[min(n, 50)][s][k] << " " << dp2[max(n - 50, 0)][sum - s][cop - k] << endl;
                    }*/
                    app = (app + (dp1[min(n, 50)][s][k]*dp2[max(n - 50, 0)][sum - s][cop - k])%MOD)%MOD;
                }
            }
            //cout << num << " " << cop << " " << app << " " << binom[amt][cop] << endl;
            if(app == binom[amt][cop])
                ans = max(ans, cop);
        }
    }
    cout << ans << endl;
}
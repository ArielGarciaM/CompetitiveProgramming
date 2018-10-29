#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input18.in", "r", stdin);
    int tri[22][22], dp[22][22];
    for(int i = 0; i < 22; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            tri[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= i; j++)
            cin >> tri[i][j];
    }
    dp[1][1] = tri[1][1];
    for(int i = 2; i <= 20; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = tri[i][j];
            int a = (j > 1) ? dp[i - 1][j - 1] : 0;
            int b = dp[i - 1][j];
            dp[i][j] += max(a, b);
        }
    }
    int mx = 0;
    for(int j = 1; j <= 20; j++)
        mx = max(mx, dp[20][j]);
    cout << mx << endl;
}
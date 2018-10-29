#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input67.in", "r", stdin);
    int tri[102][102], dp[102][102];
    for(int i = 0; i < 102; i++)
    {
        for(int j = 0; j < 102; j++)
        {
            tri[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= i; j++)
            cin >> tri[i][j];
    }
    dp[1][1] = tri[1][1];
    for(int i = 2; i <= 100; i++)
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
    for(int j = 1; j <= 100; j++)
        mx = max(mx, dp[100][j]);
    cout << mx << endl;
}
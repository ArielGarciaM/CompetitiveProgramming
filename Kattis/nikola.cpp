#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1002;
const int INF = 1e9;
int dp[MAXN][MAXN];
int arr[MAXN];


int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < MAXN; i++)
    {
        for(int j = 0; j < MAXN; j++)
            dp[i][j] = INF;
    }

    dp[1][0] = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int k = 1; k <= n; k++)
    {
        for(int i = n; i >= 1; i--)
        {
            if(i + k - 1 < n)
                dp[i][k] = min(dp[i][k], dp[i + k][k] + arr[i - 1]);
            if(i - k >= 1)
                dp[i][k] = min(dp[i][k], dp[i - k][k - 1] + arr[i - 1]);
        }
    }
    int mn = INF;
    for(int k = 0; k <= n; k++)
        mn = min(mn, dp[n][k]);
    cout << mn << endl;
}
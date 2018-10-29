#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto tStart = clock();
    long long dp[23][23];
    for(int i = 0; i < 23; i++)
    {
        for(int j = 0; j < 23; j++)
            dp[i][j] = 0;
    }
    dp[21][21] = 1;
    for(int sum = 41; sum >= 2; sum--)
    {
        for(int i = 1; i <= 21; i++)
        {
            int j = sum - i;
            if(j > 21 || j < 1)
                continue;
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    cout << dp[1][1] << endl;
    cout << "Tiempo: " << fixed << setprecision(10) << (double)(clock() - tStart)/CLOCKS_PER_SEC << "s\n";
}
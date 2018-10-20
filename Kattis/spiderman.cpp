#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        int a[50];
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        int dp[50][1010];
        string seq[50][1010];
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 1010; j++)
                dp[i][j] = -1;
        }
        dp[0][0] = 0;
        seq[0][0] = "";
        for(int step = 1; step <= n; step++)
        {
            for(int ht = 0; ht <= 1000; ht++)
            {
                int jmp = a[step];
                int small = 2000, big = 2000;
                if(ht - jmp >= 0 && dp[step - 1][ht - jmp] >= 0)
                    small = max(ht, dp[step - 1][ht - jmp]);
                if(ht + jmp <= 1000 && dp[step - 1][ht + jmp] >= 0)
                    big = dp[step - 1][ht + jmp];
                if(small + big == 4000)
                    continue;
                if(small <= big)
                {
                    dp[step][ht] = small;
                    seq[step][ht] = seq[step - 1][ht - jmp] + 'U';
                }
                else
                {
                    dp[step][ht] = big;
                    seq[step][ht] = seq[step - 1][ht + jmp] + 'D';
                }
            }
        }
        if(dp[n][0] == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << seq[n][0] << endl;
    }
}
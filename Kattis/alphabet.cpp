#include <bits/stdc++.h>
using namespace std;

int dp[55];

int main()
{
    dp[0] = 1;
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--)
        {
            if(s[j] < s[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
        mx = max(mx, dp[i]);
    cout << 26 - mx << endl;
}
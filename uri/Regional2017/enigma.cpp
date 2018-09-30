#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int main()
{
    int pows[MAXN + 5];
    char dp[MAXN + 5][MAXN + 5];
    for(int i = 0; i < MAXN + 5; i++)
        for(int j = 0; j < MAXN + 5; j++)
            dp[i][j] = '*';
    int n;
    string s;
    cin >> s >> n;
    int len = s.length();
    pows[0] = (n > 1) ? 1 : 0;
    int last[MAXN + 5][MAXN + 5];
    for(int i = 1; i < len; i++)
    {
        pows[i] = (10*pows[i - 1])%n;
    }
    dp[0][0] = '\n';
    for(int i = 1; i <= len; i++)
    {
        int m = len - i;
        if(s[m] == '?')
        {
            for(int dig = 9; dig >= 0; dig--)
            {
                if(i == len && dig == 0)
                    break;
                for(int res = 0; res < n; res++)
                {
                    if(dp[i - 1][res] == '*')
                        continue;
                    int nres = (pows[i - 1]*dig + res)%n;
                    last[i][nres] = res;
                    dp[i][nres] = '0' + dig;
                }
            }
        }
        else
        {
            int dig = s[m] - '0';
            for(int res = 0; res < n; res++)
            {
                if(dp[i - 1][res] == '*')
                    continue;
                int nres = (pows[i - 1]*dig + res)%n;
                last[i][nres] = res;
                dp[i][nres] = '0' + dig;
            }
        }
    }
    if(dp[len][0] == '*')
        cout << "*\n";
    else
    {
        int cur = 0;
        for(int i = len; i > 0; i--)
        {
            cout << dp[i][cur];
            cur = last[i][cur];
        }
        cout << endl;
    }
}
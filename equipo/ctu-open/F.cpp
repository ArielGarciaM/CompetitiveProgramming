#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 1005;

int main()
{
    int n, k;
    ll binom[MAXN][MAXN];
    for(int i = 0; i < MAXN - 1; i++)
    {
        binom[i][0] = binom[i][i] = 1;
    }
    for(int i = 2; i < MAXN - 1; i++)
    {
        for(int j = 1; j < i; j++)
        {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
        }
    }
    cin >> n >> k;
    string s;
    cin >> s;
    int ones = 0;
    ll ans = 0;
    for(int co = 0; co < n; co++)
    {
        //coinciden en los primeros co.
        if(co > 0)
            ones += (s[co - 1] == '1' ? 1 : 0);
        if(s[co] == '0')
        {
            // uno mayor con k unos, el co + 1 es 1.
            if(ones >= k)
                continue;
            ans = (ans + binom[n - 1 - co][k - ones - 1]) % MOD;
        }
        if(s[co] == '1')
        {
            // uno mayor con k - 1 unos, el co + 1 es 0.
            if(ones >= k)
                continue;
            ans = (ans + binom[n - 1 - co][k - ones - 1]) % MOD;
        }
    }
    ones += (s[n - 1] == '1' ? 1 : 0);
    if(ones == k)
        ans = (ans + 1) % MOD;
    cout << ans << endl;
}
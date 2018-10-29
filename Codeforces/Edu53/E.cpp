#include <bits/stdc++.h>
using namespace std;

string bin(int n)
{
    string ans = "";
    while(n > 0)
    {
        ans = to_string(n%2) + ans;
        n /= 2;
    }
    return ans;
}

const int MOD = 998244353;

long long amt(long long n, int k)
{
    string s = to_string(n);
    long long num[19][1024], sum[19][1024], powt[20];
    powt[0] = 1;
    for(int i = 1; i < 20; i++)
        powt[i] = (10*powt[i - 1])%MOD;
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 1024; j++)
        {
            num[i][j] = 0;
            sum[i][j] = 0;
        }
    }
    num[0][0] = 1;
    int len = s.length();
    for(int i = 0; i < len; i++)
    {
        for(long long mask = 1; mask < 1024; mask++)
        {
            int pref = 0;
            long long t = 0, prefSum = 0, numDigs = 0;
            for(int j = 0; j <= i; j++)
            {
                pref |= (1 << (s[j] - '0'));
                cout << s[j] - '0' << " " << powt[len - j - 1] << endl;
                prefSum = (prefSum + (s[j] - '0') * powt[len - j - 1])%MOD;
            }
            for(int d = 0; d < 10; d++)
            {
                if((1 << d) & mask)
                {
                    t += d;
                    numDigs++;
                }
            }
            num[i + 1][mask] = num[i][mask]*__builtin_popcountll(mask);
            sum[i + 1][mask] = (sum[i][mask] * (numDigs))%MOD;
            long long nd = ((t * num[i][mask])%MOD * powt[len - i - 1])%MOD;
            sum[i + 1][mask] = (sum[i + 1][mask] + nd)%MOD;
            if(mask == pref)
            {
                for(long long d = 9; d > (s[i] - '0'); d--)
                {
                    if((1 << d) & mask)
                    {
                        num[i + 1][mask]--;
                        sum[i + 1][mask] = (sum[i + 1][mask] - prefSum + MOD)%MOD;
                        sum[i + 1][mask] = (sum[i + 1][mask] - d*powt[len - i - 1])%MOD;
                    }
                }
            }
            for(long long d = 0; d <= 9; d++)
            {
                if((mask ^ (1 << d)) == pref && d > (s[i] - '0'))
                {
                    num[i + 1][mask]--;
                    sum[i + 1][mask] = (sum[i + 1][mask] - prefSum + MOD)%MOD;
                    sum[i + 1][mask] = (sum[i + 1][mask] - d*powt[len - i - 1])%MOD;
                }
                if(mask & 1 << d)
                {
                    num[i + 1][mask] += num[i][mask ^ (1 << d)];
                    sum[i + 1][mask] = (sum[i + 1][mask] + sum[i][mask ^ (1 << d)])%MOD;
                    long long nd = (((num[i][mask ^ (1 << d)] * d)%MOD)*powt[len - i - 1])%MOD;
                    sum[i + 1][mask] = (sum[i + 1][mask] + nd)%MOD;
                }
            }
            if(sum[i + 1][mask] > 0)
                cout << i + 1 << " " << bin(mask) << " " << sum[i + 1][mask] << "\n";
        }
    }
    long long tot = 0;
    for(int mask = 1; mask < 1024; mask++)
    {
        if(__builtin_popcount(mask) <= k)
            tot = (tot + sum[len][mask])%MOD;
    }
    return tot;
}

int main()
{
    
    long long l, r, k;
    cin >> l >> r >> k;
    cout << amt(l - 1, 2) << endl;
}
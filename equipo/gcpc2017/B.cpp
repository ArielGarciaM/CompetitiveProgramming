#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long modpow(long long a, long long b)
{
    if(b == 0)
        return 1;
    if(b % 2)
        return (a * modpow(a, b - 1))%mod;
    long long p = modpow(a, b / 2);
    return (p * p)%mod;
}

long long inv(long long x)
{
    return modpow(x, mod - 2);
}

int main()
{
    long long n, m, c;
    cin >> n >> m >> c;
    long long x = modpow(c, n*n);
    long long ans = 0;
    for(long long d = 1; d <= m; d++)
    {
        ans = (ans + modpow(x, __gcd(m, d)))%mod;
    }
    ans = (ans * inv(m))%mod;
    cout << ans << endl;
}
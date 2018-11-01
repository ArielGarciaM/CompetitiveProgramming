#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long expmod (long long b, long long e){
    long long m = MOD;
    if(!e) return 1;
    long long q= expmod(b,e/2); q=(q*q) %m;
    return e %2? (b * q) %m : q;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        long long ans = (n - 2ll + MOD)%MOD;
        ans = (ans * expmod(2ll, n + 1ll)) % MOD;
        long long aux = n - 1ll;
        aux = (aux * (expmod(2ll, n) - 1ll)) % MOD;
        ans = (ans - aux + 4ll + MOD) % MOD;
        cout << ans << endl;
    }
}
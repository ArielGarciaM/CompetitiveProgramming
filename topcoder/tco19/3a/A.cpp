#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class FamilySeatingArrangement
{
public:
    ll binom[1005][1005];
    ll MOD = 1e9 + 7;

    ll mpow(ll b, ll e) {
        ll res = 1;
        for(ll k = 1; k <= e; k <<= 1) {
            if(k & e) res = (res * b) % MOD;
            b = (b * b) % MOD;
        }
        return res;
    }

    ll f(int n, int k) {
        ll ans = 0;
        for(int i = 1; i <= k; i++) {
            ll cur = (binom[k][i] * mpow(i, n)) % MOD;
            if((k - i) % 2) cur = -cur;
            ans += cur;
            ans %= MOD;
        }
        if(ans < 0) ans += MOD;
        return ans;
    }

    int countWays(vector <int> a, int k) {
        for(int i = 0; i < 1005; i++)
            binom[i][0] = 1;
        for(int i = 0; i < 1005; i++) {
            for(int j = 1; j <= i; j++)
                binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % MOD;
        }
        int n = a.size();
        ll sig = 0;
        for(auto x : a)
            sig += x;
        ll ans = 0;
        for(int j = 1; j <= min(n, k); j++) {
            ll count = (binom[k][j] * mpow(k - j + 1, sig)) % MOD;
            count = (count * f(n, j)) % MOD;
            ans = (ans + count) % MOD;
        }
        return (int)ans;
    }
    
};

int main() {
    FamilySeatingArrangement sol;
    cout << sol.countWays({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}, 211) << endl;
}
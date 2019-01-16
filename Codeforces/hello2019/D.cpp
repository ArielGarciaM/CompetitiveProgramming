#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

struct frac {
    ll a, b;
    frac(ll num = 0, ll dem = 1) {
        a = num;
        b = dem;
    }

    frac operator+(const frac &o) {
        ll num = (a*o.b + b*o.a)%MOD;
        ll dem = (b*o.b) % MOD;
        return frac(num, dem);
    }

    frac operator*(const frac &o) {
        return frac((a*o.a)%MOD, (b*o.b)%MOD);
    }

    frac operator*=(ll c) {
        a = (a*c)%MOD;
    }
};

struct matrix {
    int n;
    vector<vector<frac>> ent;

    matrix(int n, vector<vector<frac>> &ent) : n(n), ent(ent){};

    matrix operator*(const matrix& o) {
        vector<vector<frac>> ans(n, vector<frac>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                frac res = frac(0, 1);
                for(int k = 0; k < n; k++) {
                    res = res + ent[i][k] * o.ent[k][j];
                }
                ans[i][j] = res;
            }
        }
        return matrix(n, ans);
    }
};

ll modpow(ll b, ll e) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b * modpow(b, e - 1))%MOD;
    ll p = modpow(b, e/2);
    return (p * p)%MOD;
}

ll inv(ll b) {
    return modpow(b, MOD - 2);
}

int main() {
    ll binom[100][100];
    for(int i = 0; i < 100; i++) {
        binom[0][i] = 0;
        binom[i][0] = 1;
        binom[i][i] = 1;
    }
    for(int i = 2; i < 100; i++) {
        for(int j = 1; j < i; j++) {
            binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1])%MOD;
        }
    }
    map<ll, int> fact;
    ll n, k;
    cin >> n >> k;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    bool prime = true;
    for(ll d = 2;;d++) {
        if(n % d == 0) {
            while(n % d == 0) {
                fact[d]++;
                n /= d;
            }
        }
        //cout << n << endl;
        if(n == 1)
            break;
        if(d * d > n) {
            fact[n]++;
            break;
        }
    }
    frac ans = frac(1, 1);
    for(auto pa : fact) {
        ll p = pa.first;
        int sz = pa.second;
        //cout << p << " " << sz << endl;
        vector<vector<frac>> s(sz + 1, vector<frac>(sz + 1));
        vector<vector<frac>> sp(sz + 1, vector<frac>(sz + 1));
        for(int i = 0; i <= sz; i++) {
            ll po = modpow(sz - i + 1, k);
            for(int j = i; j <= sz; j++) {
                s[i][j] = frac(binom[sz - i][j - i], 1);
                if((i + j)%2)
                    sp[i][j] = frac(MOD - s[i][j].a, po);
                else
                    sp[i][j] = frac(s[i][j].a, po);
            }
        }
        matrix d = matrix(sz + 1, s), dp = matrix(sz + 1, sp);
        matrix chain = d * dp;
        /*for(int i = 0; i <= sz; i++) {
            for(int j = 0; j <= sz; j++)
                cout << chain.ent[i][j].a << "/" << chain.ent[i][j].b << " ";
            cout << endl;
        }*/
        frac res = chain.ent[0][0];
        for(int i = 1; i <= sz; i++) {
            res *= p;
            res = res + chain.ent[0][i];
        }
        ans = ans * res;
    }
    ll p = ans.a, q = ans.b;
    cout << (p * inv(q))%MOD << endl;
}
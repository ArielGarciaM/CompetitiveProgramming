#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000000000000003;

long long mult(long long a, long long b)
{
    if(b < 0)
        return (-mult(a, -b) + MOD)%MOD;
    if(b == 0)
        return 0;
    if(b % 2ll)
        return ((a + mult(a, b - 1ll))%MOD + MOD)%MOD;
    long long m = mult(a, b/2ll);
    return ((m + m)%MOD + MOD)%MOD;
}

long long mpow(long long a, long long b)
{
    if(b == 0)
        return 1;
    if(b % 2)
        return mult(a, mpow(a, b - 1));
    long long m = mpow(a, b/2);
    return mult(m, m);
}

long long inv(long long a)
{
    return mpow(a, MOD - 2ll);
}

struct poly
{
    vector<long long> c;
    poly(const vector<long long> &c): c(c){}
    poly() {}
    poly operator+(const poly &o)
    {
        int m = c.size(), n = o.c.size();
        vector<long long> res(max(m, n));
        for(int i = 0; i < m; i++)
        {
            res[i] = (res[i] + c[i])%MOD;
        }
        for(int i = 0; i < n; i++)
        {
            res[i] = (res[i] + o.c[i])%MOD;
        }
        return poly(res);
    }
    poly operator*(const long long cons) const {
        vector<long long> res(c.size());
        for(int i = 0; i < c.size(); i++)
        {
            res[i] = mult(c[i], cons);
        }
        return poly(res);
    }
    poly operator*(const poly &o) const
    {
        int m = c.size(), n = o.c.size();
        vector<long long> res(m + n - 1);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                res[i + j] = (res[i + j] + mult(c[i], o.c[j])) % MOD;
            }
        }
        return poly(res);
    }
    long long eval(long long x)
    {
        long long sum = 0;
        for(int i = c.size() - 1; i >= 0; i--)
        {
            sum = (mult(sum, x) + c[i])%MOD;
        }
        return sum;
    }
};

vector<poly> pols;
long long fact[205];
long long invFact[205];

poly interp(vector<int> &vals)
{
    int n = vals.size() - 1;
    poly p = poly({vals[0]});
    for(int i = 1; i <= n; i++)
    {
        poly q = (pols[i] * invFact[i]);
        q = q * (vals[i] - p.eval(i));
        q = q + p;
        p = q;
    }
    return p;
}

int main()
{
    fact[0] = 1;
    for(long long i = 1; i < 205; i++)
    {
        fact[i] = mult(i, fact[i - 1]);
    }
    for(long long i = 0; i < 205; i++)
    {
        invFact[i] = inv(fact[i]);
    }
    pols.push_back(poly());
    pols.push_back(poly({0, 1}));
    for(long long i = 1; i < 205; i++)
    {
        pols.push_back(pols[i] * poly({-i, 1}));
    }
    long long k, n;
    vector<int> v;
    cin >> k >> n;
    long long val = 0;
    v.push_back(0);
    for(long long i = 1; i <= k + 1; i++)
    {
        val = (val + mpow(i, k))%MOD;
        v.push_back(val);
    }
    poly f = interp(v);
    cout << f.eval(n) << endl;
}
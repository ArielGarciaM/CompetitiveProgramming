#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll modmult(ll a, ll b, ll m)
{
    while(b < 0)
        b = (b + m)%m;
    if(b == 0)
        return 0;
    if(b % 2)
    {
        ll d = modmult(a, b - 1, m);
        ll ret = d - m;
        ret = ret + a;
        while(ret < 0)
            ret = (ret + m)%m;
        return ret;
    }
    ll s = modmult(a, b / 2, m);
    ll t = s - m;
    s = t + s;
    while(s < 0)
        s = (s + m)%m;
    return s;
}

void extendedEuclid(ll a, ll b, ll &x, ll &y)
{
    if(!b) 
    {
        x = 1;
        y = 0;
        return;
    }
    extendedEuclid(b, a % b, x, y);
    ll x1 = y;
    ll y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

pll combine(pll p1, pll p2)
{
    ll x1 = p1.first, x2 = p2.first, m1 = p1.second, m2 = p2.second;
    ll d = __gcd(m1, m2), r, s;
    if(x1 % d != x2 % d)
        return {-1, -1};
    extendedEuclid(m1, m2, r, s);
    m1 /= d;
    m2 /= d;
    ll nmod = d*m1*m2;
    ll aux1 = modmult(m1, r, nmod);
    aux1 = modmult(aux1, x2, nmod);
    ll aux2 = modmult(m2, s, nmod);
    aux2 = modmult(aux2, x1, nmod);
    ll y = (aux1 - nmod);
    y += aux2 % nmod;
    while(y < 0)
        y = (y + nmod)%nmod;
    return make_pair(y, nmod);
}

ll combineall(vector<pll> v)
{
    while(v.size() > 1)
    {
        pll p = v.back();
        v.pop_back();
        v[0] = combine(v[0], p);
        if(v[0].second == -1)
            return -1;
    }
    return v[0].first;
}

const int startit = 200;
int f[10][102];
int pos[10];
vector<int> cycle[10];
vector<pll> congs;
set<pll> sols;

int main()
{
    int B, Z;
    cin >> B >> Z;
    for(int i = 0; i < B; i++)
    {
        cin >> pos[i];
        for(int j = 1; j <= Z; j++)
            cin >> f[i][j];
    }
    for(int i = 0; i < startit; i++)
    {
        int p = pos[0];
        for(int j = 1; j < B; j++)
        {
            if(pos[j] != p)
                break;
            if(j == B - 1)
            {
                cout << p << " " << i << endl;
                return 0;
            }
        }
        for(int j = 0; j < B; j++)
        {
            pos[j] = f[j][pos[j]];
        }
    }
    ll T = startit;
    for(int i = 0; i < B; i++)
    {
        int p = pos[i];
        cycle[i].push_back(p);
        pos[i] = f[i][pos[i]];
        while(pos[i] != p)
        {
            cycle[i].push_back(pos[i]);
            pos[i] = f[i][pos[i]];
        }
    }
    for(ll x : cycle[0])
    {
        bool o = false;
        congs.clear();
        bool can = true;
        for(int i = 0; i < B; i++)
        {
            ll off = -1;
            ll mod = cycle[i].size();
            for(int j = 0; j < mod; j++)
            {
                if(cycle[i][j] == x)
                {
                    off = j;
                    break;
                }
            }
            if(off == -1)
            {
                can = false;
                break;
            }
            congs.push_back({off, mod});
        }
        if(!can)
            continue;
        ll ans = combineall(congs);
        if(ans != -1)
            sols.insert({ans, x});
    }
    if(sols.empty())
        cout << "*\n";
    else
    {
        auto p = *sols.begin();
        cout << p.second << " " << T + p.first << endl;
    }
}
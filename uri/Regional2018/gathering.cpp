#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fact[1005];
const ll MOD = 1e9 + 7;

struct pt {
    ll x, y;
    pt(ll x, ll y) : x(x), y(y){}
};

struct line {
    ll a, b, c;

    line(pt &p1, pt &p2) {
        ll a1 = p2.y - p1.y;
        ll b1 = p1.x - p2.x;
        ll c1 = -(p1.x*a1 + p1.y*b1);
        ll d = __gcd(__gcd(a1, b1), c1);
        if(abs(d) != 1) {
            a1 /= d;
            b1 /= d;
            c1 /= d;
        }
        a = a1;
        b = b1;
        c = c1;
        if(a < 0) {
            a = -a;
            b = -b;
            c = -c;
        }
    }

    bool par(line l) {
        return (a*l.b == b*l.a);
    }
};

struct LineCompare {
    bool operator()(const line &l1, const line &l2) const {
        ll d = l2.a * l1.b - l2.b * l1.a;
        return (d != 0 ? d < 0 : l1.c < l2.c);
    }
};

ll modpow(int b, int e) {
    if(e == 0)
        return 1;
    ll mu = (e % 2 ? b : 1);
    ll p = modpow(b, e/2);
    return (mu*((p*p)%MOD))%MOD;
}

ll inv(ll b) {
    return modpow(b, MOD - 2);
}

int main() {
    fact[0] = 1;
    for(ll i = 1; i < 1005; i++)
        fact[i] = (i*fact[i - 1])%MOD;
    int n;
    cin >> n;
    map<ll, ll> pts;
    for(int i = 0; i < n; i++) {
        ll x, y, z;
        cin >> x >> y;
        z = 10001ll*x + y;
        if(!pts.count(z))
            pts[z] = 0;
        pts[z]++;
    }
    vector<ll> cds, amt;
    for(auto p : pts) {
        cds.push_back(p.first);
        amt.push_back(p.second);
    }
    int m = cds.size();
    map<line, pair<pair<ll, ll>, set<ll>>, LineCompare> num;
    for(int i = 0; i < m; i++) {
        pt p1 = pt(cds[i]/10001, cds[i] % 10001);
        for(int j = i + 1; j < m; j++) {
            pt p2 = pt(cds[j]/10001, cds[j] % 10001);
            if(p1.x == p2.x || p1.y == p2.y)
                continue;
            if((p1.x > p2.x && p1.y > p2.y) || (p1.x < p2.x && p1.y < p2.y))
                continue;
            line l = line(p1, p2);
            auto &t = num[l];
            auto p = t.first;
            ll to = 0, so = 1;
            if(!t.second.count(cds[i])) {
                to += amt[i];
                so = (so * fact[amt[i]]) % MOD;
                t.second.insert(cds[i]);
            }
            if(!t.second.count(cds[j])) {
                to += amt[j];
                so = (so * fact[amt[j]]) % MOD;
                t.second.insert(cds[j]);
            }
            if(p.second > 0)
                t.first = make_pair((p.first + to)%MOD, (p.second * so)%MOD);
            else
                t.first = make_pair(to, so);
        }
    }
    ll ans = 1;
    for(auto t : amt)
        ans = (ans * fact[t]) % MOD;
    ll def = ans;
    while(!num.empty()) {
        ll os = def, o = 1;
        line l = num.begin()->first;
        while(!num.empty() && l.par(num.begin()->first)) {
            auto p = num.begin()->second.first;
            os = (os * fact[p.first]) % MOD;
            o = (o * p.second) % MOD;
            num.erase(num.begin());
        }
        os = (os * inv(o)) % MOD;
        ans = (ans + os - def) % MOD;
        if(ans < 0)
            ans += MOD;
    }
    cout << ans << endl;
}
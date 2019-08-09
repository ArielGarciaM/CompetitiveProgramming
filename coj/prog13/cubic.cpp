#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int BASE = 1e9;
const int DIGS = 13;

struct num {
    int rep[DIGS];
    num(__int128_t x = 0) {
        fill(rep, rep + DIGS, 0);
        for(int i = 0; i < 4; i++) {
            rep[i] = (int)(x % BASE);
            x /= BASE;
        }
    }
    void operator+=(const num &o) {
        for(int i = 0; i < DIGS; i++) {
            rep[i] += o.rep[i];
            if(i < DIGS - 1 && rep[i] >= BASE) {
                rep[i] -= BASE;
                rep[i + 1]++;
            }
        }
    }
    num operator+(const num &o) {
        num a = *this;
        a += o;
        return a;
    }
    num operator*(const num& o) {
        ll res[DIGS];
        fill(res, res + DIGS, 0);
        for(int i = 0; i < DIGS; i++) {
            for(int j = 0; i + j < DIGS; j++) {
                ll a = rep[i], b = o.rep[j];
                res[i + j] += a*b;
            }
        }
        ll carry = 0;
        for(int i = 0; i < DIGS; i++) {
            res[i] += carry;
            carry = res[i] / BASE;
            res[i] %= BASE;
        }
        num end;
        for(int i = 0; i < DIGS; i++)
            end.rep[i] = res[i];
        return end;
    }
    num div2() {
        num res, ex;
        for(int i = 0; i < DIGS; i++) {
            res.rep[i] = rep[i]/2;
            if(i && (rep[i] & 1))
                ex.rep[i - 1] = BASE/2;
        }
        return res + ex;
    }
    string to_str() {
        string res, tmp;
        for(int i = DIGS - 1; i >= 0; i--) {
            tmp = to_string(rep[i]);
            reverse(tmp.begin(), tmp.end());
            while(tmp.size() < 9) tmp += '0';
            reverse(tmp.begin(), tmp.end());
            res += tmp;
        }
        int p = 0;
        while(res[p] == '0')
            p++;
        if(p == res.size())
            return "0";
        return res.substr(p);
    }
    string dir() {
        string res;
        for(int i = DIGS - 1; i >= 0; i--) {
            res += to_string(rep[i]);
            res += " ";
        }
        return res;
    }
    bool operator> (const num &o) const {
        for(int i = DIGS - 1; i >= 0; i--)
            if(rep[i] != o.rep[i]) return rep[i] > o.rep[i];
        return false;
    }
    bool operator!= (const num &o) const {
        for(int i = 0; i < DIGS; i++)
            if(rep[i] != o.rep[i]) return true;
        return false;
    }
};

num p10(int e) {
    int x = 1;
    int a = e/9, b = e - 9*a;
    while(b--)
        x *= 10;
    num res;
    res.rep[a] = x;
    return res;
}

num coob(__int128_t target) {
    num t = num(target);
    t = t * p10(84);
    num lo, hi = p10(38);
    while(hi > lo) {
        num mi = (lo + hi).div2();
        num coobie = mi*mi*mi;
        if(t > coobie)
            lo = mi + num(1);
        else
            hi = mi;
    }
    //cout << lo.to_str() << endl;
    return lo;
}

struct turn {
    int to, idx;
    ld cost;
    bool operator<(const turn &o) const { 
        if(cost != o.cost) return cost > o.cost;
        return idx < o.idx;
    }
};

const int MAXN = 5e5 + 5;
const int LOG = 62;
int n, J, q, nxt[LOG][MAXN];
ld cost[LOG][MAXN];

turn adv(int s, long long k, int i) {
    ld res = 0;
    for(ll l = 0; l < LOG; l++) {
        if(k & (1LL << l)) {
            ld a = cost[l][s];
            res = cbrt(res*res*res + a*a*a);
            s = nxt[l][s];
        }
    }
    return turn({s, i, res});
}

string CUTE(string res) {
    if(res == "0") return "0.00000";
    reverse(res.begin(), res.end());
    string s = res.substr(23), t = res.substr(0, 23);
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    long long l = stoll(s);
    //dec = stoll(t);
    if(t > "50000000000000000000000")
        l++;
    res = to_string(l);
    res = res.substr(0, res.size() - 5) + "." + res.substr(res.size() - 5);
    return res;
}

void test_case() {
    for(int i = 1; i <= n; i++) {
        ll c;
        cin >> nxt[0][i] >> c;
        cost[0][i] = c;
    }

    for(int l = 0; l < LOG - 1; l++) {
        for(int i = 1; i <= n; i++) {
            nxt[l + 1][i] = nxt[l][nxt[l][i]];
            ld a = cost[l][i], b = cost[l][nxt[l][i]]; 
            cost[l + 1][i] = cbrt(a*a*a + b*b*b);
        }
    }

    cin >> J >> q;
    while(q--) {
        vector<turn> turns;
        for(int i = 0; i < J; i++) {
            int st;
            ll k;
            cin >> st >> k;
            turns.clear();
            turns.push_back(adv(st, k, i));
        }
        turn t = *(min_element(turns.begin(), turns.end()));
        cout << t.idx + 1 << " " << t.to << " " << fixed << setprecision(5) << t.cost << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n)
        test_case();
}
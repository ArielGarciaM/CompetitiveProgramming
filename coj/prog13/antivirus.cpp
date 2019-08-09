#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;
const int INF = 2e9;
ll BIT[MAXN];
int a[MAXN], xd[MAXN], xdd[MAXN];
int n;

void upd(int p, ll v) {
    for(;p < MAXN;p += (p & -p)) BIT[p] += v;
}

ll sum(int p) {
    ll res = 0;
    for(;p > 0; p -= (p & -p)) res += BIT[p];
    return res;
}

struct tree {
    int t[2*MAXN];

    void build() {
        for(int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
    }

    void upd(int p, int v) {
        for(t[p += n] = v; p > 1; p >>=1) t[p>>1] = min(t[p], t[p^1]);
    }

    int qry(int l, int r) {
        int res = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) res = min(res, t[l++]);
            if(r&1) res = min(res, t[--r]);
        }
        return res;
    }
};
tree hr, hl;

bool check(int p, int spread) {
    int r = min(n, p + spread);
    assert(p < r);
    if(spread > hr.qry(p, r) - p) return false;
    r = max(0, p - spread + 1);
    assert(r < p + 1);
    if(spread > hl.qry(r, p + 1) + p) return false;
    return true;
}

int main() {

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        hr.t[i + n] = a[i] + i;
        hl.t[i + n] = a[i] - i;
        upd(i + 1, a[i]);
    }
    hr.build();
    hl.build();
    int q;
    scanf("%d", &q);
    while(q--) {
        int t, i, x;
        scanf("%d %d %d", &t, &i, &x);
        i--;
        if(t == 1) {
            hr.upd(i, x + i);
            hl.upd(i, x - i);
            upd(i + 1, x - a[i]);
            a[i] = x;
        }
        else {
            int lo = 1, hi = a[i];
            if(x == 1) hi = min(i + 1, n - i);
            while(lo < hi) {
                int mi = (lo + hi + 1)/2;
                if(check(i, mi))
                    lo = mi;
                else
                    hi = mi - 1;
            }
            ll to = lo, out;
            ll s = sum(min(i + lo, n)) - sum(max(i - lo + 1, 0));
            if(i - to + 1 < 0) {
                out = to - i - 1;
                s += (out * (out + 1))/2;
            }
            if(i + to - 1 >= n) {
                out = i + to - n;
                s += (out * (out + 1))/2;
            }
            printf("%d %lld\n", lo, s - to*to);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18;

//template<class T>
struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    pt operator+ (pt o) const {return pt(x + o.x, y + o.y);}
    pt operator- (pt o) const {return pt(x - o.x, y - o.y);}
    pt operator* (ll l) const {return pt(l*x, l*y);}
    ll normsq() {return x*x + y*y;}
};

typedef pt P;

const int MAXN = 1e4 + 5;
int n;
ll X[MAXN], dp[MAXN], maxr[MAXN], minl[MAXN], h, alpha, beeta;
P poly[MAXN];

bool canr(ll l, ll r) {
    if(l == r) return true;
    P cen = P{X[r], h - (X[r] - X[l])};
    ll rad = X[r] - X[l];
    //cout << l << " " << r << " " << cen.x << " " << cen.y << " " << rad << endl;
    for(int i = l + 1; i <= r - 1; i++) {
        ll x = poly[i].x, y = poly[i].y;
        P oth = P{X[l] + 2*(x - X[l]), h - 2*(h - y)};
        if(oth.y > cen.y && (cen - oth).normsq() > rad*rad)
            return false;
    }
    return true;
}

bool canl(ll l, ll r) {
    if(l == r) return true;
    P cen = P{X[l], h - (X[r] - X[l])};
    ll rad = X[r] - X[l];
    for(int i = l + 1; i <= r - 1; i++) {
        ll x = poly[i].x, y = poly[i].y;
        P oth = P{X[r] - 2*(X[r] - x), h - 2*(h - y)};
        if(oth.y > cen.y && (cen - oth).normsq() > rad*rad)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h >> alpha >> beeta;
    for(int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        X[i] = x;
        poly[i] = P{x, y};
    }
    for(int l = 1; l <= n; l++) {
        int lo = l, hi = n;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(canr(l, mi))
                lo = mi;
            else
                hi = mi - 1;
        }
        maxr[l] = lo;
    }
    for(int r = 1; r <= n; r++) {
        int lo = 1, hi = r;
        while(lo < hi) {
            int mi = (lo + hi)/2;
            if(canl(mi, r))
                hi = mi;
            else
                lo = mi + 1;
        }
        minl[r] = lo;
    }
    //for(int i = 1; i <= n; i++) {
    //    cout << minl[i] << " " << maxr[i] << endl;
    //}
    fill(dp, dp + MAXN, INF);
    dp[1] = alpha*(h - poly[1].y);
    for(int r = 2; r <= n; r++) {
        for(int l = 1; l <= n; l++) {
            ll dis = X[r] - X[l];
            if(l < minl[r] || r > maxr[l] || 2ll*poly[l].y > 2ll*h - dis || 2ll*poly[r].y > 2ll*h - dis)
                continue;
            dp[r] = min(dp[r], dp[l] + beeta*(X[r] - X[l])*(X[r] - X[l]) + alpha*(h - poly[r].y));
        }
    }
    if(dp[n] == INF)
        cout << "impossible\n";
    else
        cout << dp[n] << endl;
}
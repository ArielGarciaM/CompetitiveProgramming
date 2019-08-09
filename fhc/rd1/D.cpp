#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<ii> pts;

bool can(ll L) {
    ll ly = L, uy = 0, lx = L, ux = 0;
    set<ii> bad;
}

ll solve() {
    int n, h, v;
    ll x1, x2, ax, bx, cx, dx, y1, y2, ay, by, cy, dy;
    cin >> n >> h >> v >> x1 >> x2 >> ax >> bx >> cx >> dx >> y1 >> y2 >> ay >> by >> cy >> dy;
    pts.clear();
    pts.push_back({x1, y1});
    pts.push_back({x2, y2});
    for(int i = 3; i <= n; i++) {
        ll tx = x2, ty = y2;
        x2 = ((ax * x1 + bx * x2 + cx) % dx) + 1;
        y2 = ((ay * y1 + by * y2 + cy) % dy) + 1;
        x1 = tx;
        y1 = ty;
        pts.push_back({x2, y2});
    }
    //for(auto p : pts)
    //    cout << "(" << p.first << ", " << p.second << ")\n";
    if(h + v < n)
        return -1;

    ll lo = 0, hi = 1e10;
    while(lo < hi) {
        ll mi = (lo + hi)/2;
        if(can(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    return lo;
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << '\n';
}
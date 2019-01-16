#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld INF = 1e12;

struct point {
    ld x, y;
    point(ld x, ld y) : x(x), y(y){}
};

struct line {
    ld a, b, c;
    
    line(point p1, point p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = -(p1.x*a + p1.y*b);
    }

    ld eval(point p) {
        return a*p.x + b*p.y + c;
    }

    ld dist(point p) {
        return eval(p)/hypot(a, b);
    }
};

int main() {
    int n;
    vector<point> ps;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ld x, y;
        cin >> x >> y;
        ps.push_back(point(x, y));
    }
    ld ans = INF;
    for(int i = 0; i < n; i++) {
        point p1 = ps[i];
        for(int j = i + 1; j < n; j++) {
            point p2 = ps[j];
            line l = line(p1, p2);
            ld mn = 0.0, mx = 0.0;
            for(auto p : ps) {
                ld d = l.dist(p);
                mn = min(mn, d);
                mx = max(mx, d);
            }
            ans = min(ans, mx - mn);
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
}
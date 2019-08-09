#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;
    pt operator+ (const pt &o) {
        return pt{x + o.x, y + o.y};
    }

    pt operator-(const pt &o) {
        return pt{x - o.x,y - o.y};
    }

    pt operator*(const double &c) {
        return pt{c*x, c*y};
    }
};

double dot(pt p1, pt p2) {
    return p1.x*p2.x + p1.y*p2.y;
}

double normsq(pt p) {
    return dot(p, p);
}

double dist(pt p1, pt p2) {
    return sqrt(normsq(p2 - p1));
}

pt proj(pt a, pt p1, pt p2) {
    pt u = p2 - p1;
    double lam = dot(a - p1, u)/normsq(u);
    return p1 + u*lam;
}

bool inseg(pt p1, pt p2, pt p3) {
    return (fabs(dist(p1, p2) + dist(p2, p3) - dist(p1, p3)) < 1e-8);
}

double dist(pt a, pt p1, pt p2) {
    pt b = proj(a, p1, p2);
    if(inseg(p1, b, p2))
        return dist(a, b);
    return min(dist(a, p1), dist(a, p2));
}

double dist(pt p1, pt p2, pt q1, pt q2) {
    return min({dist(p1, q1, q2), dist(p2, q1, q2), dist(q1, p1, p2), dist(q2, p1, p2)});
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pt> v(n);
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v[i] = pt{x, y};
    }
    if(m + k < n + 2 || m + k > n + 4) {
        cout << -1 << endl;
        return 0;
    }
    double ans = 1e9;
    if(m + k == n + 2) {
        for(int i = 0; i < n; i++) {
            ans = min(ans, dist(v[i], v[(i + m - 1)%n]));
            ans = min(ans, dist(v[i], v[(i + k - 1)%n]));
        }
    }
    if(m + k == n + 3) {
        for(int i = 0; i < n; i++) {
            ans = min(ans, dist(v[i], v[(i + m - 2)%n], v[(i + m - 1)%n]));
            ans = min(ans, dist(v[i], v[(i + k - 2)%n], v[(i + k - 1)%n]));
        }
    }
    if(m + k == n + 4) {
        for(int i = 0; i < n; i++) {
            ans = min(ans, dist(v[i], v[(i + 1)%n], v[(i + m - 2)%n], v[(i + m - 1)%n]));
            ans = min(ans, dist(v[i], v[(i + 1)%n], v[(i + k - 2)%n], v[(i + k - 1)%n]));
        }
    }
    cout << fixed << setprecision(3) << ans << endl;
}

//(a - p1 - l*u)*u = 0
//(a - p1)*u/(u * u) = l
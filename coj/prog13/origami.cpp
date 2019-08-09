#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int TOT = 1e6 + 5;
const ld EPS = 1e-9;
int ans[TOT];

struct pt {
    ll x, y;
    pt(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    pt operator-(const pt &o) { return pt(x - o.x, y - o.y); }
    ll cross(pt o) { return x*o.y - y*o.x; }
    ll normsq() { return x*x + y*y; }
    ld norm() { return hypot(x, y); }
    ll cross(pt a, pt b) { return (a - *this).cross(b - *this); }
};

ll dis(pt &a, pt &b) {
    return (a - b).normsq();
}

vi manacher(const vector<ld> &s) {
    int n = s.size();
    vi P(n);
    int L = -1, R = -1;
    // [i - P[i], i + P[i]] palin
    for(int i = 0; i < n; i++) {
        if(i <= R) P[i] = min(P[L + R - i], R - i);
        while(i + P[i] + 1 < n && i - P[i] - 1 >= 0 && fabs(s[i + P[i] + 1] - s[i - P[i] - 1]) < EPS)
            P[i]++;
        if(i + P[i] > R) {
            L = i - P[i];
            R = i + P[i];
        }
    }
    return P;
}

int solve() {
    int n;
    cin >> n;
    vector<pt> poly;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        poly.push_back(pt(x, y));
    }
    vector<ld> rep;
    for(int i = 0; i < n; i++) {
        pt A = poly[i];
        pt B, C;
        if(i + 1 < n)
            B = poly[i + 1];
        else
            B = poly[i + 1 - n];
        if(i + 2 < n)
            C = poly[i + 2];
        else
            C = poly[i + 2 - n];
        ld p = (B - A).norm(), q = (B - C).norm();
        rep.push_back(dis(A, B));
        rep.push_back(B.cross(A, C)/(p*q));
    }
    for(int i = 0; i < 2*n; i++)
        rep.push_back(rep[i]);
    auto pal = manacher(rep);
    /*for(int i = 0; i < 4*n; i++)
        cout << rep[i] << " ";
    cout << '\n';
    for(int i = 0; i < 4*n; i++)
        cout << pal[i] << " ";
    cout << '\n';*/
    int ans = 0;
    for(int i = 0; i < 4*n; i++)
        if(pal[i] >= n) ans++;
    return ans/2;
}

void test_case() {
    int P, mx = 0, ct = 0;
    cin >> P;
    for(int i = 0; i < P; i++) {
        ans[i] = solve();
        cout << ans[i] << '\n';
        mx = max(mx, ans[i]);
    }
    for(int i = 0; i < P; i++)
        if(ans[i] == mx) ct++;
    cout << mx << " " << ct << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        test_case();
}
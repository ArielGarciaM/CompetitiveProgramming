#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

vector<ld> p1, q1, p2, q2;
int k;
ld d, W, D, A, eps = 1e-9;

ld f1(ld x) {
    ld p = 0.0, q = 0.0;
    for(int i = k; i >= 0; i--) {
        p *= x;
        q *= x;
        p += p1[i];
        q += q1[i];
    }
    return p/q;
}

ld f2(ld x) {
    ld p = 0.0, q = 0.0;
    for(int i = k; i >= 0; i--) {
        p *= x;
        q *= x;
        p += p2[i];
        q += q2[i];
    }
    return p/q;
}

ld g1(ld x) {
    return max(f1(x), -d);
}

ld g2(ld x) {
    return max(f2(x), -d);
}

ld integ(ld (*f)(ld), ld a, ld b) {
    ld its = 1000.0;
    ld h = (b - a) / 2 / its;
    ld v = f(a) + f(b);
    for(int i = 1; i < 2*its; i++)
        v += f(a + i * h) * (i&1 ? 4 : 2);
    return v * h/3;
}

ld bs() {
    ld lo = 0.0, hi = D;
    for(int i = 0; i < 400; i++) {
        ld mi = (lo + hi)/2.0;
        d = mi;
        ld a = integ(g1, 0, W) - integ(g2, 0, W);
        if(a < A + eps)
            lo = mi;
        else
            hi = mi;
    }
    return lo;
}

int main() {
    while(cin >> W >> D >> A >> k) {
        p1.resize(k + 1);
        p2.resize(k + 1);
        q1.resize(k + 1);
        q2.resize(k + 1);
        for(int i = 0; i < k + 1; i++)
            cin >> p1[i];
        for(int i = 0; i < k + 1; i++)
            cin >> q1[i];
        for(int i = 0; i < k + 1; i++)
            cin >> p2[i];
        for(int i = 0; i < k + 1; i++)
            cin >> q2[i];
        cout << fixed << setprecision(5) << bs() << endl;
    }
}

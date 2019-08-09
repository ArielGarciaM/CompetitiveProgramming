#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld EPS = 1e-15;
ld a, b, c, d, L;

ld getx(ld y) {
    return c + (y - d)*(c - a)/(d - 2.0*y + b);
}

pair<ld, ld> bs() {
    ld hi = min(b, d), lo = -1e9;
    for(int it = 0; it < 1000; it++) {
        ld mi = (lo + hi)/2.0;
        ld x = getx(mi);
        if(hypot(x - a, mi - b) + hypot(x - c, mi - d) <= L + EPS)
            hi = mi;
        else
            lo = mi;
    }
    return pair<ld, ld>{getx(lo), lo};
}

int main() {
    cout << fixed << setprecision(20);
    while(cin >> a >> b >> c >> d >> L) {
        if(fabs(b - d) < EPS) {
            ld d = fabs(a - c);
            ld x = (a + c)/2.0;
            ld y = min(b, d) - sqrt(L*L/4.0 - d*d/4.0);
            cout << x << " " << y << '\n';
            continue;
        }
        auto p = bs();
        cout << p.first << " " << p.second << '\n';
    }
}
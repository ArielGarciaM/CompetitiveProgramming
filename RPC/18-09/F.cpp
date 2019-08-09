#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld PI = acos(-1);
const ld eps = 1e-5;

// (x, y) -> x*(cos a, sin a) + y*(-sin a, cos a) = (x*cos a - y*sin a, x*sin a + y*cos a)
template <typename T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point operator+ (const Point& o) { return Point(x + o.x, y + o.y); }
    Point operator- (const Point& o) { return Point(x - o.x, y - o.y); }
    Point operator* (T a) { return Point(a*x, a*y); }
    Point operator/ (T a) { return Point(x/a, y/a); }
    bool operator== (const Point &o) { return (abs(x - o.x) < eps && abs(y - o.y) < eps); }
    T dot(const Point& o) { return x*o.x + y*o.y; }
    T normsq() { return x*x + y*y; }
    ld norm() { return hypot(x, y); }
    Point unit() { return *this/(norm()); }
    Point perp() { return Point(-y, x); }
    Point rotate(ld a) { return Point(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)); }
    ld ang() { return atan2(y, x); }
};

typedef Point<ld> P;

P anglecenter(P A, P B, ld theta) {
    P C = B - A;
    P M = (A + B) / 2.0;
    P t = C.perp().unit();
    ld c = tan(theta/2.0);
    return M + t*((C.norm()/2.0)/c);
}

P proj(P A, P B, P C) {
    P v = B - A;
    ld t = v.dot(C - A)/v.normsq();
    return A + v*t;
}

P ref(P X, P Y) {
    if(X == Y)
        return X*2;
    P Z = proj(X, Y, P(0, 0));
    return Z*2;
}

int n;
ld rAng, gAng, bAng, alpha, black, oblk;
P BP(-1, 0);
P RP = BP.rotate(2*PI/3.0);
P GP = BP.rotate(4*PI/3.0);
P O = (0, 0);

P solve(ld a1, ld a2) {
    P O1 = anglecenter(O, BP, 2.0*a1), O2 = anglecenter(RP, O, 2*a2);
    return ref(O1, O2);
}

const int MAXN = 1e6 + 5;
int seen[3];
ld rx[MAXN], gx[MAXN], bx[MAXN];

void gayG() {
    P ctr = anglecenter(BP, O, 2.0*bAng);
    P X = proj(O, GP, ctr);
    P res = X*2;
    ld theta = (BP - res).ang();
    theta = (theta - oblk + alpha/2.0);
    cout << fixed << setprecision(10) << res.x << " " << res.y << " " << theta << endl;
    exit(0);
}

void gayB() {
    P ctr = anglecenter(RP, O, 2.0*rAng);
    P X = proj(O, BP, ctr);
    P res = X*2;
    ld theta = (RP - res).ang();
    theta = (theta - oblk + alpha/2.0);
    cout << fixed << setprecision(10) << res.x << " " << res.y << " " << theta << endl;
    exit(0);
}

void gayR() {
    P ctr = anglecenter(GP, O, 2.0*gAng);
    P X = proj(O, RP, ctr);
    P res = X*2;
    ld theta = (GP - res).ang();
    theta = (theta - oblk + alpha/2.0);
    cout << fixed << setprecision(10) << res.x << " " << res.y << " " << theta << endl;
    exit(0);
}

void tryGay() {
    if(fabs(rAng) > eps && fabs(bAng) > eps && fabs(gAng) > eps)
        return;
    if(fabs(gAng) < eps) {
        for(int i = 0; i < n; i++) {
            if(bx[i] > eps)
                return;
            if(rx[i] > eps)
                gayG();
        }
    }
    if(fabs(bAng) < eps) {
        for(int i = 0; i < n; i++) {
            if(rx[i] > eps)
                return;
            if(gx[i] > eps)
                gayB();
        }
    }
    if(fabs(rAng) < eps) {
        for(int i = 0; i < n; i++) {
            if(gx[i] > eps)
                return;
            if(bx[i] > eps)
                gayR();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    bool add = true;
    cin >> n >> alpha;
    for(int i = 0; i < n; i++) {
        ld r, g, b;
        cin >> r >> g >> b;
        rx[i] = r;
        gx[i] = g;
        bx[i] = b;
        rAng += r;
        gAng += g;
        bAng += b;
        if(add)
            black += (1.0 - r - g - b);
        if(r + g + b > eps)
            add = false;
    }
    //cout << s << endl;
    rAng *= alpha/(ld)n;
    bAng *= alpha/(ld)n;
    gAng *= alpha/(ld)n;
    black *= alpha/(ld)n;
    oblk = alpha - rAng - bAng - gAng - black;
    P res;
    ld theta;
    tryGay();
    if(true) {
        res = solve(bAng, rAng);
        if((res.ang() <= -PI/3.0 && ( fabs(gAng) < eps || (-PI/6.0 <= (BP - res).ang() && (BP - res).ang() <= PI/6.0 && fabs(fabs((BP - res).ang() - (GP - res).ang()) - gAng) < eps)
            || (PI/2.0 <= (RP - res).ang() && (RP - res).ang() <= 5.0*PI/6.0 && fabs(fabs((RP - res).ang() - (GP - res).ang()) - gAng) < eps) ))) {
            theta = (RP - res).ang();
            if(PI/2.0 <= (RP - res).ang() && (RP - res).ang() <= 5.0*PI/6.0)
                theta = (GP - res).ang();
            theta = (theta - oblk + alpha/2.0);
            cout << fixed << setprecision(10) << res.x << " " << res.y << " " << theta << endl;
            return 0;
        }
    }
    if(true) {
        res = solve(rAng, gAng).rotate(2.0*PI/3.0);
        theta = (GP - res).ang();
        if((res.ang() >= -PI/3.0 && res.ang() <= PI/3.0 && ( fabs(bAng) < eps || (PI/2.0 <= (RP - res).ang() && (RP - res).ang() <= 5.0*PI/6.0 && fabs(fabs((RP - res).ang() - (BP - res).ang()) - bAng) < eps) ||
            (PI/6.0 <= (GP - res).ang() && (GP - res).ang() <= PI/2.0 && fabs(fabs((GP - res).ang() - (BP - res).ang()) - bAng) < eps) ))) {
            theta = (GP - res).ang();
            if(PI/6.0 <= (GP - res).ang() && (GP - res).ang() <= PI/2.0)
                theta = (BP - res).ang();
            theta = (theta - oblk + alpha/2.0);
            cout << fixed << setprecision(10) << res.x << " " << res.y << " " << theta << endl;
            return 0;
        }
    }
    if(true) {
        res = solve(gAng, bAng).rotate(4.0*PI/3.0);
        if(res.ang() >= PI/3) {
            theta = (BP - res).ang();
            if(-PI/6.0 <= (BP - res).ang() && (BP - res).ang() <= PI/6.0)
                theta = (RP - res).ang();
            theta = (theta - oblk + alpha/2.0);
            cout << fixed << setprecision(10) << res.x << " " << res.y << " " << theta << endl;
            return 0;
        }
    }
}
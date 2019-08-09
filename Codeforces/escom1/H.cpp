#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const ld PI = acos(-1);
ld A, B, P, om, Phi;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> om;
    while(n--) {
        ld a, phi;
        cin >> a >> phi;
        A += a*cos(phi);
        B += a*sin(phi);
    }
    P = sqrt(A*A + B*B);
    Phi = atan2(B, A);
    if(Phi < 0)
        Phi += 2.0*PI;
    cout << fixed << setprecision(15) << P << " " << Phi << '\n';
}
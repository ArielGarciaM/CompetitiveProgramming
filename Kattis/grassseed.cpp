#include <bits/stdc++.h>
using namespace std;

int main() {
    double c;
    int l;
    cin >> c >> l;
    double t = 0;
    while(l--) {
        double x, y;
        cin >> x >> y;
        t += x*y;
    }
    cout << fixed << setprecision(10) << c*t << endl;
}
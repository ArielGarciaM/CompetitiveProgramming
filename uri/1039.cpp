#include <bits/stdc++.h>
using namespace std;
typedef double ld;

int main() {
    int r1, x1, y1, r2, x2, y2;
    while(cin >> r1) {
        cin >> x1 >> y1 >> r2 >> x2 >> y2;
        if(hypot(x1 - x2, y1 - y2) + r2 <= r1)
            cout << "RICO\n";
        else
            cout << "MORTO\n";
    }
}
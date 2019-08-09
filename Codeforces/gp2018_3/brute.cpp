#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<int, int> ii;

struct circle {
    ld x, y, r;
    int idx;
    bool operator< (const circle &o) const { return r < o.r; }
};

bool isect(circle c1, circle c2) {
    ld d = hypot(c1.x - c2.x, c1.y - c2.y);
    return d > fabs(c1.r - c2.r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<circle> every;
    for(int i = 0; i < n; i++) {
        ld X, Y, R;
        cin >> X >> Y >> R;
        every.push_back({X, Y, R, i});
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(isect(every[i], every[j]))
                ans += 2;
            if(ans > 2*n) {
                cout << "greater\n";
                return 0;
            }
        }
    }

    cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;
typedef double ld;

struct circle {
    ld x, y, r;
    bool operator< (const circle &o) const { return r < o.r; }
};

bool isect(circle c1, circle c2) {
    ld d = hypot(c1.x - c2.x, c1.y - c2.y);
    return d > fabs(c1.r - c2.r);
}

ostream& operator<< (ostream& out, circle c) {
    out << "(" << c.x << ", " << c.y << ") " << c.r;
    return out;
}

vector<circle> every;
int n, ans = 0;
vector<int> sons[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        ld X, Y, R;
        cin >> X >> Y >> R;
        every.push_back({X, Y, R});
    }
    sort(every.begin(), every.end());
    for(int i = 1; i < n; i++) {
        int cur = -1;
        for(int j = i - 1; j >= 0; j--) {
            if(isect(every[i], every[j])) {
                ans += 2;
                if(ans > 2*n) {
                    cout << "greater\n";
                    return 0;
                }
                sons[i].push_back(j);
            }
            else {
                cur = j;
                break;
            }
        }
        if(cur > -1) {
            while(cur) {
                bool done = true;
                for(auto j : sons[cur]) {
                    if(isect(every[i], every[j])) {
                        ans += 2;
                        if(ans > 2*n) {
                            cout << "greater\n";
                            return 0;
                        }
                        sons[i].push_back(j);
                    }
                    else {
                        cur = j;
                        done = false;
                        break;
                    }
                }
                if(done)
                    break;
            }
        }
    }
    cout << ans << endl;
}